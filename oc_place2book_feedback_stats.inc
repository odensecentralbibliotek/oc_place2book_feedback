<?php

function oc_place2book_feedback_stats_view($nid) {
    /*
     * If a node is selected , get its data and prebare it for charing.
     */
    $selected_node = $nid;
    /*
     * Extract data for chart.
     */
    $node = node_load($selected_node);
    $pie_data = build_node_pie_data($node);
    $bar_data = build_node_bar_data($node);
    $textarea_data = build_user_additional_comments($node);
    /*
     * Render the chart + additional data for the given node data.
     */
    drupal_add_js(drupal_get_path('module', 'oc_place2book_feedback') . '/js/highcharts.js');

    drupal_add_js(drupal_get_path('module', 'oc_place2book_feedback') . '/js/jquery.tablesorter.pager.js');
    
    drupal_add_css(drupal_get_path('module', 'oc_place2book_feedback') . '/css/tablesort_pager.css');
    drupal_add_css(drupal_get_path('module', 'oc_place2book_feedback') . '/css/oc_place2book_stats.css');

    return theme('oc_p2b_stats_view_index', array('pie_data' => $pie_data, 'textarea_data' => $textarea_data,'bar_data' => $bar_data));
}

function get_events_feedback_sendt() {
    $result = db_query('SELECT ding_place2book_feedback.nid as nid FROM ding_place2book_feedback join node on ding_place2book_feedback.nid = node.nid where ding_place2book_feedback.feedback_sendt = 1 and node.status = 0;')->fetchAllKeyed(0, 0);
    $return = array();
    foreach ($result as $value) {
        array_push($return, $value);
    }
    return $return;
}

function build_user_additional_comments($node) {
    if (!isset($node) || $node == false) {
        return array();
    }
    $sids = get_all_sids_for_nid($node->nid);
    $webform_id = get_node_webform($node->nid);
    $webform_node = node_load($webform_id);
    if (sizeof($sids) == 0 || $webform_id == false) {
        return null;
    }
    $components = $webform_node->webform['components'];
    $headers = array(
        t('Yderligere kommentare')
    );
    $data = array();
    foreach ($sids as $sid) {
        $webform_response_data = get_sid_data($sid);
        foreach ($webform_response_data as $sid_data) {
            foreach ($components as $cid => $component) {
                $type = $component['type'];
                if ($type == "textarea" && $component['cid'] == $sid_data->cid) {
                    if (!isset($data[$component['name']])) {
                        $data[$component['name']] = array();
                    }
                    if ($sid_data->data != "") {
                        $data[$component['name']][] = array(array('data' => $sid_data->data));
                    }
                }
            }
        }
    }

    // Make the table...
    foreach ($data as $textarea) {
        $output = theme('table', array('header' => $headers, 'rows' => $textarea, 'attributes' => array('class' => array('tablesorter'))));
    }

    // Return the output with the pager attached to it.  The pager 
    // is the box underneath the table that allows people to jump 
    // to the next page.
    return $output;
}

function build_node_pie_data($node) {
    try {
        if (!isset($node) || $node == false) {
            return array();
        }
        $sids = get_all_sids_for_nid($node->nid);
        $webform_id = get_node_webform($node->nid);
        $webform_node = node_load($webform_id);
        if (sizeof($sids) == 0 || $webform_id == false) {
            return null;
        }
        // Get the callback to use, depending on the component.
        $components = $webform_node->webform['components'];

        $data = array();
        foreach ($sids as $sid) {
            $webform_response_data = get_sid_data($sid);
            foreach ($webform_response_data as $sid_data) {
                foreach ($components as $cid => $component) {
                    if ($sid_data->cid == $component['cid']) {
                        /*
                         * build result set.
                         */
                        $type = $component['type'];
                        if ($type == "select") {
                            if (!isset($data[$component['name']])) {
                                $data[$component['name']] = array();
                            }
                            $found = false;
                            foreach ($data[$component['name']] as $i => $pie_data) {
                                if ($pie_data['name'] == $sid_data->data) {
                                    $data[$component['name']][$i]['y'] += 1;
                                    $found = true;
                                    break;
                                }
                            }
                            if ($found == false) {
                                $data[$component['name']][] = array('name' => $sid_data->data, 'y' => 1);
                            }
                        }
                        break;
                    }
                }
            }
        }
        return $data;
    } catch (Exception $ex) {
        return null;
    }
}
function build_node_bar_data($node) {
    try {
        if (!isset($node) || $node == false) {
            return array();
        }
        $sids = get_all_sids_for_nid($node->nid);
        $webform_id = get_node_webform($node->nid);
        $webform_node = node_load($webform_id);
        if (sizeof($sids) == 0 || $webform_id == false) {
            return null;
        }
        // Get the callback to use, depending on the component.
        $components = $webform_node->webform['components'];

        $data = array();
        foreach ($sids as $sid) {
            $webform_response_data = get_sid_data($sid);
            foreach ($webform_response_data as $sid_data) {
                foreach ($components as $cid => $component) {
                    if ($sid_data->cid == $component['cid']) {
                        /*
                         * build result set.
                         */
                        $type = $component['type'];
                        if ($type == "select") {
                            if (!isset($data[$component['name']])) {
                                $data[$component['name']] = array();
                            }
                            $found = false;
                            foreach ($data[$component['name']] as $i => $pie_data) {
                                if ($pie_data['name'] == $sid_data->data) {
                                    $data[$component['name']][$i]['data'][0] += 1;
                                    $found = true;
                                    break;
                                }
                            }
                            if ($found == false) {
                                $data[$component['name']][] = array('name' => $sid_data->data, 'data' => array(1));
                            }
                        }
                        break;
                    }
                }
            }
        }
        return $data;
    } catch (Exception $ex) {
        return null;
    }
}
function get_sid_data($sid) {
    $result = db_query('SELECT * FROM webform_submitted_data where sid = ' . $sid)->fetchAll();
    return $result;
}

function get_all_sids_for_nid($nid) {
    $result = db_query('SELECT sid FROM webform_submitted_data where data= ' . $nid)->fetchAllKeyed(0, 0);
    $return = array();
    foreach ($result as $value) {
        array_push($return, $value);
    }
    return $return;
}

function get_node_webform($nid) {
    $result = db_query('SELECT nid FROM webform_submitted_data where data= ' . $nid)->fetchAllKeyed(0, 0);
    $return = array();
    foreach ($result as $value) {
        array_push($return, $value);
    }
    return reset($return);
}
function oc_place2book_feedback_stats_output_pdf($nid)
{
     global $base_url;
     $pdf_filename = "feedback_" . $nid;
     $meta = array();
     $html = "<html><head><meta charset='UTF-8'>";
     $html .= "<script src='https://code.jquery.com/jquery-3.2.1.min.js'></script>";
     $html .= "<script src='".$base_url."/".drupal_get_path('module', 'oc_place2book_feedback') . '/js/highcharts.js'."'></script>";
     $html .= "<link rel='stylesheet' type='text/css' href='".$base_url."/".drupal_get_path('module', 'oc_place2book_feedback') . '/css/oc_p2b_stats_print.css'."'>";
     //$html .= "<script src='".$base_url."/".drupal_get_path('module', 'oc_place2book_feedback') . '/js/jquery.tablesorter.pager.js'."'></script>";
     $html .="</head><body>";
     $html .= oc_place2book_feedback_stats_view($nid);
     $html.="</body></html>";
     
     $pdf = print_pdf_generate_html($html,$meta);
     print_pdf_dispose_content($pdf, $pdf_filename);
     drupal_exit();   
}
