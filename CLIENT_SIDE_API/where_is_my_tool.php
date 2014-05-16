<link type="text/css" rel="stylesheet" href="../css/where_is_my_tool.css">
<link type="text/css" rel="stylesheet" href="../css/smoothness/jquery-ui-1.10.4.custom.css">
<script src="../scripts/jquery-1.11.1.js"></script>
<script src="../scripts/jquery-ui-1.10.4.custom.js"></script>

<div>
    <h1>Where is my tool ?</h1>
    <div id="menu">
	<ul id="tabs">
	    <li id="detect_local"><a href="services/local_detection.php"> Local </a></li>
	    <li id="detect_distant"><a href="services/distant.php"> Distant </a></li>
	</ul>
    </div>
    <div id="action_bar">
	<form action="<?php echo $_SERVER['HTTP_REFERER'];?>" method="post" id="ip_form">
		<button type="submit" id="connect_button">Connect</button>
	    	<button type="button" id="manual_settings_button">Manual Settings</button>
	    	<button type="button" id="refresh_button">Refresh</button>
	</form>
    </div>
</div>
<div id="manual_settings_dialog_background" style="display: none"></div>
<div id="manual_settings_dialog" style="display: none">
    <h1>manual settings</h1>
    <form action="<?php echo $_SERVER['HTTP_REFERER'];?>" method="post" id="manual_form">
        <div id="manual_ip_field"></div>
	<button type="submit" id="connect_button">Connect</button>
    </form>
</div>
<script>
$(function() {
	$( "#menu" ).tabs({
		beforeLoad: function( event, ui ) {
		        ui.panel.empty();
			$('#action_bar button').attr("disabled", "disabled");
		        ui.panel.css('background','url("/images/wait.gif") no-repeat center');       
			ui.jqXHR.error(function() {
				ui.panel.css('background','');  
        			ui.panel.html("Ajax request fail : Not implemented yet. ");
				$('#refresh_button').removeAttr("disabled");
				$('#manual_settings_button').removeAttr("disabled");
        		});
     		 }
	});


	$( "#menu" ).tabs({
		load: function( event, ui ) {
			ui.panel.css('background','');
			$('#list_devices li:even').addClass("device_odd") ;
			$('#refresh_button').removeAttr("disabled");
			$('#manual_settings_button').removeAttr("disabled");
			$('input[name=device_choice]').remove();
			$('#ip_form').append('<input type="hidden" name="device_choice">');
			$('#list_devices li').click(function(){
				 $( "input[name=device_choice]" ).val( $(this).attr('value') );
				 $('#list_devices li').removeAttr('selected');
				 $(this).attr('selected','selected');
				 $("#connect_button").removeAttr("disabled");
			});
			$("#manual_settings_button").click(function() {
				$('#manual_settings_dialog_background').show("fade");
				$('#manual_settings_dialog').show("fade");
				$('input[name=device_choice]').remove();
				$('#manual_ip_field').append('Ip Adress: <input type="text" name="device_choice">');
   			});
			$("#refresh_button").click(function() {
				$( "#menu" ).tabs("load",$("#menu").tabs( "option", "active"));
   			});
			$('#manual_settings_dialog_background').click(function() {
				$('#manual_ip_field').empty();
				$('#ip_form').append('<input type="hidden" name="device_choice">');
				$('#manual_settings_dialog_background').hide("fade");
				$('#manual_settings_dialog').hide("fade");
				

			});
      		}
	});


});
</script>

