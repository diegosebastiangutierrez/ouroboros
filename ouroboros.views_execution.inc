<?php

function ouroboros_views_query_alter($view, $query) {
  
  if ($view->id() == 'efemerides'){
    
    $display = $view->getDisplay()->display['id'];
    $data = date('dm');
    $data_page = date('m');
    
    switch($display){
    
      case "block_1":
        $query->where[1]['conditions'][]= array('field' => "DATE_FORMAT(taxonomy_term__field_fecha_nacimiento.field_fecha_nacimiento_value, '%m') = '$data_page'",'value'=> [],'operator' => 'formula');
      break;
      case "block_2":
        $query->where[1]['conditions'][]= array('field' => "DATE_FORMAT(taxonomy_term__field_fecha_deceso.field_fecha_deceso_value, '%m') = '$data_page'",'value'=> [],'operator' => 'formula');

      break;
      case "page_1":
        $query->where[1]['conditions'][]= array('field' => "DATE_FORMAT(taxonomy_term__field_fecha_nacimiento.field_fecha_nacimiento_value, '%m') = '$data_page'",'value'=> [],'operator' => 'formula');
      break;
      case "block_3":
        $query->where[1]['conditions'][]= array('field' => "DATE_FORMAT(taxonomy_term__field_fecha_deceso.field_fecha_deceso_value, '%m') = '$data_page'",'value'=> [],'operator' => 'formula');

      break;
    
    }
    
  }

}
