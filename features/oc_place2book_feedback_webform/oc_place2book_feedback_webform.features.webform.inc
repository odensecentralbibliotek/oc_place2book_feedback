<?php
/**
 * @file
 * oc_place2book_feedback_webform.features.webform.inc
 */

/**
 * Implements hook_webform_defaults().
 */
function oc_place2book_feedback_webform_webform_defaults() {
$webforms = array();
  $webforms['arrangements_feedback'] = array(
  'title' => 'Arrangements feedback',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 1,
  'sticky' => 0,
  'vuuid' => '3b4383f5-ec2b-4b26-84e6-02d9e5eea1ca',
  'type' => 'webform',
  'language' => 'da',
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'd57e200f-19a2-4965-b27f-6ed82e056fd4',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p><strong><span style="font-size:14px;">Kære deltager,</span></strong></p><p><strong><span style="font-size:14px;">Du har for kort tid siden deltaget i et arrangement arrangeret af Odense Bibliotekerne.</span></strong></p><p><strong><span style="font-size:14px;">Vi vil meget gerne høre din mening om dette, så vi kan udvikle vores tilbud og blive bedre.</span></strong><br>&nbsp;</p><hr><p>&nbsp;</p>',
        'summary' => '',
        'format' => 'ding_wysiwyg',
        'safe_value' => '<p><strong><span style="font-size:14px;">Kære deltager,</span></strong></p>
<p><strong><span style="font-size:14px;">Du har for kort tid siden deltaget i et arrangement arrangeret af Odense Bibliotekerne.</span></strong></p>
<p><strong><span style="font-size:14px;">Vi vil meget gerne høre din mening om dette, så vi kan udvikle vores tilbud og blive bedre.</span></strong><br>&nbsp;</p>
<hr>
<p>&nbsp;</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'webform' => array(
    'confirmation' => '',
    'confirmation_format' => 'ding_wysiwyg',
    'redirect_url' => '<confirmation>',
    'status' => 1,
    'block' => 0,
    'teaser' => 0,
    'allow_draft' => 0,
    'auto_save' => 0,
    'submit_notice' => 1,
    'submit_text' => '',
    'submit_limit' => -1,
    'submit_interval' => -1,
    'total_submit_limit' => -1,
    'total_submit_interval' => -1,
    'webform_ajax' => 0,
    'charting' => 'a:2:{s:7:"backend";s:28:"webform_chart_bundler_charts";s:13:"config_method";s:1:"1";}',
    'machine_name' => 'arrangements_feedback',
    'record_exists' => TRUE,
    'roles' => array(
      0 => 1,
      1 => 2,
    ),
    'emails' => array(),
    'components' => array(
      'arrangements_feedback__event_nid' => array(
        'form_key' => 'event_nid',
        'name' => 'event_nid',
        'type' => 'hidden',
        'value' => '',
        'extra' => array(
          'private' => FALSE,
          'hidden_type' => 'value',
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
        ),
        'mandatory' => 0,
        'weight' => 0,
        'charting' => NULL,
        'machine_name' => 'arrangements_feedback__event_nid',
        'page_num' => 1,
      ),
      'arrangements_feedback___p_en_skala_fra_1_til_5_hvor_5_e' => array(
        'form_key' => '_p_en_skala_fra_1_til_5_hvor_5_er_bedst_hvordan_vil_du_vurdere_arrangemanget_',
        'name' => ' På en skala fra 1 til 5, hvor 5 er bedst, hvordan vil du vurdere arrangementet som helhed?',
        'type' => 'select',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'aslist' => 0,
          'optrand' => 0,
          'conditional_operator' => '=',
          'items' => '1|1
2|2
3|3
4|4
5|5
',
          'multiple' => 0,
          'custom_keys' => 0,
          'other_option' => NULL,
          'other_text' => 'Andet...',
          'description' => '',
          'options_source' => '',
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => 0,
        'weight' => 1,
        'charting' => 'a:2:{s:8:"activate";i:1;s:6:"config";a:3:{s:11:"#chart_type";s:3:"pie";s:6:"#width";s:3:"250";s:7:"#height";s:3:"250";}}',
        'machine_name' => 'arrangements_feedback___p_en_skala_fra_1_til_5_hvor_5_e',
        'page_num' => 1,
      ),
      'arrangements_feedback___p_en_skala_fra_1_til_5_hvor_5_3' => array(
        'form_key' => '_p_en_skala_fra_1_til_5_hvor_5_er_bedst_hvordan_vil_du_vurdere_underviseren_',
        'name' => ' På en skala fra 1 til 5, hvor 5 er bedst, hvordan vil du vurdere underviseren?',
        'type' => 'select',
        'value' => '',
        'extra' => array(
          'items' => '1|1
2|2
3|3
4|4
5|5
',
          'multiple' => FALSE,
          'aslist' => FALSE,
          'optrand' => 0,
          'other_option' => NULL,
          'other_text' => 'Andet...',
          'title_display' => 'before',
          'description' => '',
          'custom_keys' => 0,
          'options_source' => '',
          'private' => 0,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
          'value' => 1,
        ),
        'mandatory' => 0,
        'weight' => 2,
        'charting' => NULL,
        'machine_name' => 'arrangements_feedback___p_en_skala_fra_1_til_5_hvor_5_3',
        'page_num' => 1,
      ),
      'arrangements_feedback___p_en_skala_fra_1_til_5_hvor_5_2' => array(
        'form_key' => '_p_en_skala_fra_1_til_5_hvor_5_er_bedst_hvordan_vil_du_vurdere_arrangemengets_varighed_',
        'name' => ' På en skala fra 1 til 5, hvor 5 er bedst, hvordan vil du vurdere arrangementets varighed?',
        'type' => 'select',
        'value' => '',
        'extra' => array(
          'items' => '1|1
2|2
3|3
4|4
5|5
',
          'multiple' => FALSE,
          'aslist' => FALSE,
          'optrand' => 0,
          'other_option' => NULL,
          'other_text' => 'Andet...',
          'title_display' => 'before',
          'description' => '',
          'custom_keys' => 0,
          'options_source' => '',
          'private' => 0,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
          'value' => 1,
        ),
        'mandatory' => 0,
        'weight' => 3,
        'charting' => NULL,
        'machine_name' => 'arrangements_feedback___p_en_skala_fra_1_til_5_hvor_5_2',
        'page_num' => 1,
      ),
      'arrangements_feedback__yderlige_kommentare' => array(
        'form_key' => 'yderlige_kommentare',
        'name' => 'Yderlige kommentare',
        'type' => 'textarea',
        'value' => '',
        'extra' => array(
          'cols' => 60,
          'rows' => 5,
          'title_display' => 0,
          'resizable' => 1,
          'disabled' => 0,
          'description' => '',
          'attributes' => array(),
          'private' => 0,
          'conditional_component' => '',
          'conditional_operator' => '=',
          'conditional_values' => '',
        ),
        'mandatory' => 0,
        'weight' => 4,
        'charting' => NULL,
        'machine_name' => 'arrangements_feedback__yderlige_kommentare',
        'page_num' => 1,
      ),
    ),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 37413,
  'comment_count' => 0,
  'name' => 'tfpet',
  'picture' => 0,
  'data' => 'a:1:{s:18:"htmlmail_plaintext";i:0;}',
  'print_html_display' => 1,
  'print_html_display_comment' => 0,
  'print_html_display_urllist' => 1,
  'webform_features_author' => 'tfpet',
  'webform_features_revision_author' => '',
);
return $webforms;
}
