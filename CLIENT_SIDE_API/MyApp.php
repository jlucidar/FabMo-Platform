<?php include 'template/ShopBot_header.php' ?>
<?php
if (isset($_POST["device_choice"]) && !empty($_POST["device_choice"]))
{
	$tool_ip = $_POST["device_choice"];
}
?>

<link type="text/css" rel="stylesheet" href="./css/MyApp.css">
<script src="./scripts/jquery-1.11.1.js"></script>
<script src="../scripts/jquery-ui-1.10.4.custom.js"></script>

<h1> Send some stuff to your tool </h1>

<button id="select_a_tool_button">Select a tool</button>
<div id="select_a_tool_div" style="display: none"></div>
<div id="select_a_tool_background" style="display: none"></div>

<?php if (isset($tool_ip)) { ?>
<br>
<br>
<div id='tool_info'>
    <h2>Connected to the tool !</h2>
    ip : <?php echo $tool_ip ?>
</div>
    <br>
    <br>
<div id="send_data">
    <h2> Send him some data ! </h2>
    <form action="http://<?php echo $tool_ip?>" method="post" id="send_data_form">
	<textarea id="data_textarea" name="data"></textarea><br>
	<button id="send_data_button" type="button">Send</button>
    </form>
    <div id="send_data_reply"></div>
</div>
<?php } ?>

<script>
$(function() {
    $('#select_a_tool_button').click(function() {
	$("#select_a_tool_div").load('where_is_my_tool.php');
	$("#select_a_tool_background").show('fade');
	$("#select_a_tool_div").show('fade');
    });
    $('#select_a_tool_background').click(function() {
	$("#select_a_tool_div").unload;
	$("#select_a_tool_background").hide('fade');
	$("#select_a_tool_div").hide('fade');
    });

    <?php if (isset($tool_ip)) { ?>
    var device_choice = '<?php echo $tool_ip ?>' ;
    $( "#send_data_button" ).click(function() {
    	$.post( $('#send_data_form').attr("action"), { data:  $('#data_textarea').find( "#data" ).val() } ).done(function( my_data ) {
    		$( "#send_data_reply" ).empty().append( "Reply :<br>" + my_data);
	});
    });

    <?php } ?>



});
</script>

<?php include 'template/ShopBot_footer.php' ?>
