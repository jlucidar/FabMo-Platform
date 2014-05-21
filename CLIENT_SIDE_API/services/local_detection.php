<?php

$devices_list_json_string = shell_exec("../core/detect.sh");
if( $devices_list_json_string =='')
{
	echo 'no device found';
}
else
{
	$devices_list = json_decode($devices_list_json_string);

	$count_array = array(); // used for getting a unique device list.

	// make a list of uniques devices ( currently based on the hostname and need to be replace with a serial number )
	foreach (($devices_list) as $dev)
	{
		$count_array[] = $dev->device->hostname;
	}
	$count_array = array_unique($count_array);


	$new_device_array = array(); // new JSON object, represent the devices that you can connect to.
	
	// new JSON object constructor
	foreach (($count_array) as $single_dev)
	{
		$dev_interfaces = array(); // reset the interfaces array for every new device
		$dev_hostname = $single_dev; // get the hostname

		// get the interface array
		foreach (($devices_list) as $device) // array with all the ips and net interfaces separately
		{
			if( $device->device->hostname == $single_dev ) //select the ones corresponding to the current device
			{
				foreach (($device->device->networks) as $network) // list the interfaces
				{
					if ( $network->ip_address == $device->active_ip ) //select active interfaces.
					{
						$dev_interfaces[] = array('interface' => $network->{'interface'}, 'ip_address' => $network->ip_address); // add theses to the network section
					}
				}
			}
		}
		// add the device to the new_device_array
		$new_device_array[] = array( "hostname" => $dev_hostname, "network" => $dev_interfaces);
	}


	echo "<ul id=\"list_devices\">";
	foreach ((json_decode(json_encode($new_device_array))) as $device)
	{
		echo "<li value='".json_encode($device)."'>".$device->hostname."</li>";
	}
	echo "</ul>
";

}

 ?>
