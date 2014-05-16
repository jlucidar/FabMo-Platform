<?php

$devices_list = shell_exec("../core/detect.sh");
#$devices_list = "a.a.a.a\nb.b.b.b\nc.c.c.c\nd.d.d.d\na.a.a.a\nb.b.b.b\nc.c.c.c\nd.d.d.d\n";
if( $devices_list =='')
{
	echo 'no device found';
}
else
{
	echo "<ul id=\"list_devices\">";
	foreach (explode("\n",$devices_list) as $device)
	{
		if( $device !='')
		{
			$device_arg=explode(":",$device);
			# no support for the nickname of the device and other informations for the time
			$ip_addr = $device_arg[1];
			$name = $device_arg[0];

			echo "
	<li value=\"$ip_addr\">
		name : $name
		<br>
		ip : $ip_addr
	</li>
";
		}
	}
	echo "</ul>
";

}

 ?>
