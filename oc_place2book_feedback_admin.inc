<?php
function oc_place2book_feedback_form_ding_place2book_admin_settings_form_alter(&$form, &$form_state, $form_id)
{
      $form['ding_place2book_feedback_survey'] = array(
        '#type' => 'fieldset',
        '#title' => t('Place2Book Feedback settings'),
        '#collapsible' => TRUE,
        '#collapsed' =>  TRUE,
      );
      $data = variable_get("ding_place2book_feedback_survey",'');
      $form['ding_place2book_feedback_survey']['oc_place2book_feedback_survey_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Survey Url'),
        '#default_value' => isset($data["oc_place2book_feedback_survey_url"]) ?  $data["oc_place2book_feedback_survey_url"] : "",
        '#description' => t('Survey Url that is used when collecting feedback'),
        '#attributes' => array('placeholder' => 'Webform url, survey-xact url or any other url.'),
      );
      $form['ding_place2book_event_nodes']['defaults']['#options']['place2book_send_feedback'] = t("Send survey feedback on end of p2b based event");

}

