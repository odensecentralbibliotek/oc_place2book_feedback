<?php

function oc_place2book_feedback_form_ding_place2book_admin_settings_form_alter(&$form, &$form_state, $form_id) {
    $form['ding_place2book_feedback_survey'] = array(
        '#type' => 'fieldset',
        '#title' => t('Place2Book Feedback settings'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $data = variable_get("ding_place2book_feedback_survey", '');

    $select_data = array();
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
                    ->entityCondition('bundle', 'webform')
                    ->propertyCondition('status', NODE_PUBLISHED)->execute();
    if (isset($result['node'])) {
        $webform_items_nids = array_keys($result['node']);
        $webform_items = entity_load('node', $webform_items_nids);
        foreach ($webform_items as $item) {
            $select_data[$item->nid] = $item->title;
        }
    }
    /*
     * Migth be used in the future , if other kind of surveys will be sendt.
     *  $form['ding_place2book_feedback_survey']['oc_place2book_feedback_survey_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Survey Url'),
      '#default_value' => isset($data["oc_place2book_feedback_survey_url"]) ?  $data["oc_place2book_feedback_survey_url"] : "",
      '#description' => t('Survey Url that is used when collecting feedback'),
      '#attributes' => array('placeholder' => 'Webform url, survey-xact url or any other url.'),
      ); */

    $form['ding_place2book_feedback_survey']['oc_place2book_feedback_survey_nid'] = array(
        '#type' => 'select',
        '#title' => t('Webform til feedback'),
        '#options' => $select_data,
        '#default_value' => isset($data["oc_place2book_feedback_survey_nid"]) ? $data["oc_place2book_feedback_survey_nid"] : "",
        '#description' => t('Den webform som bliver sendt ud til event deltagere.'),
    );

    $form['ding_place2book_event_nodes']['defaults']['#options']['place2book_send_feedback'] = t("Send survey feedback on end of p2b based event");
}
