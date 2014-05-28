<?php include 'template/ShopBot_header.php' ?>
<?php
if (isset($_POST["device_choice"]) && !empty($_POST["device_choice"]))
{
	$tool_json = $_POST["device_choice"];
	$tool = json_decode($tool_json);
}
?>

<link type="text/css" rel="stylesheet" href="./css/MyApp.css">
<script src="./scripts/jquery-1.11.1.js"></script>
<script src="../scripts/jquery-ui-1.10.4.custom.js"></script>

<h1> Send some stuff to your tool </h1>

<button id="select_a_tool_button">Select a tool</button>
<div id="select_a_tool_div" style="display: none"></div>
<div id="select_a_tool_background" style="display: none"></div>

<?php if (isset($tool)) {?>
<br>
<br>

<div id='tool_info'>
    <h2>Connected to the tool !</h2>
    hostname : <?php echo $tool->hostname ?><br>
    networks : <?php echo "<ul id=\"list_networks\">";
	foreach (( $tool->network) as $net)
	{
		echo "<li>Ip Address : ".$net->ip_address."<br>  interface : ".$net->{'interface'}."</li>";
	}
	echo "</ul>";
		?>

</div>
<br>
<div id="send_data">
    <h2> Debug Tool </h2>

<?php
// automatic selection of the best way to talk to the tool
// base on this priority : usb > ethernet > wifi > wifi-direct
	foreach (( $tool->network) as $net)
	{
		if($net->{'interface'} == "wlan1")
		{
			$selcted_ip = $net->ip_address;
		}
	}
	foreach (( $tool->network) as $net)
	{
		if($net->{'interface'} == "wlan0")
		{
			$selcted_ip = $net->ip_address;
		}
	}
	foreach (( $tool->network) as $net)
	{
		if($net->{'interface'} == "eth0")
		{
			$selcted_ip = $net->ip_address;
		}
	}
	foreach (( $tool->network) as $net)
	{
		if($net->{'interface'} == "usb0")
		{
			$selcted_ip = $net->ip_address;
		}
	}
?>


    <form action="http://<?php echo $selcted_ip?>" method="post" id="send_data_form" style="float:left;width:45%;">
	Path of the service (let blank if / ) : <br><input type="text" id="service_path"><br>
	Data to send :<br> <textarea id="data_textarea" style="overflow: auto;
resize: none;
height: 120px;
width: 275px;">{}</textarea><br>
	<button id="send_data_button" type="button">Send</button>
    </form>
    <div id="receive_data_field">Data received : <br><textarea id="received_data_textarea" disabled=true style="overflow: auto;
resize: none;
height: 175px;
width: 380px;"></textarea><br></div>
</div>


<?php } ?>

<script>
$(function() {
    $('#select_a_tool_button').click(function() {
	$("#select_a_tool_div").load('where_is_my_tool.html');
	$("#select_a_tool_background").show('fade');
	$("#select_a_tool_div").show('fade');
    });
    $('#select_a_tool_background').click(function() {
	$("#select_a_tool_div").unload;
	$("#select_a_tool_background").hide('fade');
	$("#select_a_tool_div").hide('fade');
    });

    <?php if (isset($tool)) { ?>
    $( "#send_data_button" ).click(function(event) {
        var url = $('#send_data_form').attr('action') + '/' + $('#service_path').val() + '?callback=?';
	event.preventDefault();
	$.ajax({
            url: url,
	    type: "POST",
	    jsonp : 'jsonp',
	    dataType: 'jsonp',
	    data: JSON.parse($('#data_textarea').val()),
	    contentType: "jsonp",
	    cache: true,
	    success: function(my_data){
	    	//var my_data_json =  JSON.parse(my_data);
	   	var my_data_string =  JSON.stringify(my_data, null, "\t");
	    	$( "#received_data_textarea" ).empty().append(my_data_string );
	    },
	    error: function(jqxhr){
	    	console.log(jqxhr);
	    }
        });
    });
    <?php } ?>
});
  
</script>
<?php include 'template/ShopBot_footer.php' ?>
