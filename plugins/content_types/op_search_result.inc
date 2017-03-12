<?php
/**
 * @file
 * Panels render to display search results.
 */

$plugin = array(
  'title' => t('Open platform'),
  'description' => t('Open platform search results'),
  'required context' => new ctools_context_required(t('Keywords'), 'string'),
  'category' => t('Ting'),
  'content_types' => array('ting_search'),
  'render callback' => 'ting_open_platform_op_search_result_content_type_render',
  'render first' => TRUE,
  'render last' => FALSE,
);

/**
 * Render the custom content type.
 */
function ting_open_platform_op_search_result_content_type_render($subtype, $conf, $panel_args, $context) {
  $keys = NULL;
  if (!empty($context) && isset($context->data)) {
    $keys = $context->data;
  }
  // Build the content type block.
  $block = new stdClass();
 
//  $result = ting_open_platform_search($keys);
//  if (isset($result->data)) {
//     $block->content = ting_open_platform_render_cover($result->data);  
//  }
  $result = ting_inspiration_list_search($keys); 
  
  $block->content = $result;
  $path = drupal_get_path('module', 'ting_inspiration_list');
  drupal_add_css($path . '/css/ting_inspiration_list.css');
  drupal_add_js(drupal_get_path('module', 'ting_covers') . '/js/ting-covers.js');
  return $block;
}

/**
 * Returns the administrative title for a type.
 */
function ting_open_platform_op_search_result_content_type_admin_title($form, &$form_state) {
  return $form;
}


