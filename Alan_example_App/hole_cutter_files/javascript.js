function user_action(var_action) {
	if(var_action.substring(0,6) == 'modal_') {
		var_modal = var_action.replace("modal_","");
		$(this[var_modal]).foundation('reveal', 'open');
	} else if(var_action.length > 1) {
		document.location.href = var_action;
	} 
	return false;
}

function confirm_idea_link_delete(appIdeaId, id){
	var resultOfConfirm = confirm("Are you sure you want to remove this link?");
	if (resultOfConfirm == true) {
		document.body.style.cursor = "wait";
		document.location.href='proc/idea_submit_url_delete_proc.php?appIdeaId='+appIdeaId+"&id="+id;		
	}
}

function confirm_idea_file_delete(appIdeaId, file){
	var resultOfConfirm = confirm("Are you sure you want to remove this photo?");
	if (resultOfConfirm == true) {
		document.body.style.cursor = "wait";
		document.location.href='proc/idea_submit_file_delete_proc.php?appIdeaId='+appIdeaId+"&file="+file;		
	}
}

function submit_idea(submit_override) {
	if($('#file_primaryPhoto').val() == '' && check_for_main == 1) {
		alert('Please select the main photo for this idea.');		
	} else {
		document.location.href = 'proc/idea_submit_3_proc.php';
	}
}


//$(function(){ //docready
$(document).ready(function(){

	// if baseball card text overflows box, add ellipsis
	  $('.app-ideas .ideas li .box-inner p.desc').each(function(){
	    var $this = $(this);
	    if ($this.get(0).scrollHeight > $this.height()) {
	        $this.append('<span class="ellipsis">&#133;</span>');
	      }
	  });
	
	
	var $container = $("#idea_container");
	
	$container.isotope({itemSelector : '.item',
	  animationEngine: 'best-available',
	  getSortData : {
		name : function ( $elem ) {
		  return $elem.find('.name').text();
		},
		screenName : function ( $elem ) {
		  return $elem.find('.screenName').text();
		},		
		date : function ( $elem ) {
		  return $elem.find('.date').text();
		},
		rating_value : function ( $elem ) {
			return $elem.find('.rating_value').text();
			//return $("#rating_value").val();
		}
	  }
	});
	
	$('#filters a').click(function(){
  var selector = $(this).attr('data-option-value');
  $container.isotope({ filter: selector });
  return false;
});

	var $optionSets = $('#filters.option-set, #sort-by.option-set, #sort-direction.option-set'),	
		$optionLinks = $optionSets.find('a');
		
      $optionLinks.click(function(){
        var $this = $(this);
        // don't proceed if already selected
        if ( $this.hasClass('selected') ) {
          return false;
        }
        var $optionSet = $this.parents('.option-set');
        $optionSet.find('.selected').removeClass('selected');
        $this.addClass('selected');
  
        // make option object dynamically, i.e. { filter: '.my-filter-class' }
        var options = {},
            key = $optionSet.attr('data-option-key'),
            value = $this.attr('data-option-value');
        // parse 'false' as false boolean
        value = value === 'false' ? false : value;
        options[ key ] = value;
        if ( key === 'layoutMode' && typeof changeLayoutMode === 'function' ) {
          // changes in layout modes need extra logic
          changeLayoutMode( $this, options )
        } else {
          // otherwise, apply new options
          $container.isotope( options );
        }
        
        return false;
      });
		
		
	$(".sort-by a, .sort-order a").click(function(){
        var $this = $(this);
        // don't proceed if already selected
        if ( $this.hasClass('selected') ) {
          return false;
        }
        var $optionSet = $this.parent();
        $optionSet.find('.selected').removeClass('selected');
        $this.addClass('selected');
  
        // make option object dynamically, i.e. { filter: '.my-filter-class' }
        var options = {},
            key = $optionSet.attr('data-option-key'),
            value = $this.attr('href').split("=")[1];
        // parse 'false' as false boolean
        value = value === 'false' ? false : value;
        options[ key ] = value;

	  // otherwise, apply new options
	  $container.isotope( options );
 
        return false;
      });
});


function login_alert() {
	$('#login').foundation('reveal', 'open');
}


function frm_login_submit() {
	//alert('hey');				
	$('#login_message').html('Please Wait...');	
	$.post('proc/login_proc.php', $("#frm_login").serialize(), function(data) {																		
		$('#login_message').html(data);		
	});
}


function frm_forgot_password_submit() {
	//alert('hey');				
	$('#forgot_password_message').html('Please Wait...');	
	$.post('proc/login_forgot_password_proc.php', $("#frm_forgot_password").serialize(), function(data) {				
		//alert('hey');									
		$('#forgot_password_message').html(data);		
	});								
	$("#forgot_password_message").trigger("create");
}

function frm_sign_up_submit() {
	//alert('hey');				
	$('#sign_up_message').html('Please Wait...');	
	$.post('proc/sign_up_proc.php', $("#frm_sign_up").serialize(), function(data) {				
		//alert('hey');									
		$('#sign_up_message').html(data);		
	});								
	$("#sign_up_message").trigger("create");
}

function frm_support_submit() {
	//alert('hey');	
	$('#support_message').html('Please Wait...');	
	$.post('proc/support_proc.php', $("#frm_support").serialize(), function(data) {				
		//alert('hey');									
		$('#support_message').html(data);		
	});								
	$("#support_message").trigger("create");
}

function frm_profile_edit_submit() {
	//alert('hey');				
	$('#profile_edit_message').html('Please Wait...');	
	$.post('proc/profile_edit_proc.php', $("#frm_profile_edit").serialize(), function(data) {				
		//alert('hey');									
		$('#profile_edit_message').html(data);		
	});								
	$("#profile_edit_message").trigger("create");	
}