/**
 * @author jimmy
 */
var uniq = require('uniq');
var http = require('http');

var util  = require('util'),
    spawn = require('child_process').exec;


exports.where_is_my_tool = function(req, res, next) {
	// execute the cmd command
	var cmd = './services/detect.sh',result='';
	spawn(cmd).stdout.on('data', function (data) {
		result += data;
	})
	.on('end',function(){
		/*****************************************************************/
		if( result === '')
		{
			res.send('no device found');
		}
		else
		{
			try{
				var devices_list = JSON.parse(result);
			}
			catch (e) {
				devices_list= [];
			}

			var count_array = []; // used for getting a unique device list.

			// make a list of unique devices ( currently based on the hostname and need to be replace with a serial number )
			for(var dev in devices_list)
			{
				count_array.push(devices_list[dev].device.hostname);
			}
			count_array = uniq(count_array);


			var new_device_array = []; // new JSON object, represent the devices that you can connect to.
			
			// new JSON object constructor
			for (var single_dev in count_array)
			{
				var dev_interfaces = []; // reset the interfaces array for every new device
				var dev_hostname = count_array[single_dev]; // get the hostname

				// get the interface array
				for(var device in devices_list) // array with all the ips and net interfaces separately
				{
					if( devices_list[device].device.hostname === count_array[single_dev] ) //select the ones corresponding to the current device
					{
						for(var network in devices_list[device].device.networks) // list the interfaces
						{
							if (  devices_list[device].device.networks[network].ip_address === devices_list[device].active_ip ) //select active interfaces.
							{
								dev_interfaces.push({'interface' :  devices_list[device].device.networks[network].interface, 'ip_address' :  devices_list[device].device.networks[network].ip_address}); // add theses to the network section
							}
						}
					}
				}
				// add the device to the new_device_array
				new_device_array.push({ "hostname" : dev_hostname, "network" : dev_interfaces});
			}
		}
			/*********************************************************************/
		console.log(new_device_array);
		res.json(new_device_array);
	});
    next();
};

exports.are_you_a_sbt = function(req, res, next) {
	var cmd = './services/are_you_a_sbt '+req.params[0] + ' && echo "}"',result='';
	spawn(cmd).stdout.on('data', function (data) {
		result += data;
	})
	.on('close',function(code){
		if (result === '' )
			res.send(204);
		else
			res.json(JSON.parse(result));
	});
    next();
};

exports.local_detection = function(req, res, next) {

	var serv = res;
	http.get({port:8080,path: '/where_is_my_tool'},function(res){
		res.on('data', function (data) {
			var device_list = JSON.parse(''+data);
			serv.write("<ul id=\"list_devices\">");
			for(device in device_list)
			{
				serv.write("<li value='" + JSON.stringify(device_list[device]) + "'>" + device_list[device].hostname + "</li>");
			}
			serv.write("</ul>");
		    serv.end();
		  });
	});

    next();
};


