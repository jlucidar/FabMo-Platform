var os=require('os');
var util=require('util');
var EventEmitter = require('events').EventEmitter;
var dgram = require('dgram');

var OK = "YES I M !\0";
var ERR = "I DNT UNDRSTND !\0";
var HOSTNAME = "U NAME ?\0";
var REQ = "R U A SBT ?\0";

var broadcastAddress = '255.255.255.255';
var broadcastPort = 24862; // = 7777 without conversion


var detection = function(t) {
	var socket = dgram.createSocket('udp4');
	var current_dialog =[];
	var device;
	var devices =[];
	
	var timeout = t || 1000;
	var that =this;
	socket.bind(function(){
		socket.setBroadcast(true);});

		socket.on("message", function ( data, rinfo ) {
			if(data.toString() == OK)
			{
				//console.log("response from : " +rinfo.address);
				socket.send(new Buffer(HOSTNAME), 0, HOSTNAME.length, broadcastPort, rinfo.address, function (err) {
							if (err) console.log(err);
							//console.log("ask info");
						});
				current_dialog.push(rinfo.address); // add ip in an array
			}
			else if(current_dialog.indexOf(rinfo.address)!==-1) // if the device is a sbt, continue the dialog.
			{
				current_dialog.splice(current_dialog.indexOf(rinfo.address), 1); //end of dialog (remove ip from array )
				//substract \0 character of the string before parsing.
				device = JSON.parse('{"device" : ' + data.toString().replace('\0', '') + ',"active_ip" : "'+ rinfo.address+'"}');
				devices.push(device);
				//console.log(device + " added !");
				that.emit('new_device',device);
			}
			else
			{
				console.log("[detection_tool.js] received from "+rinfo.address+" : unknow message : '"+ data.toString() +"'");
			}
		});

		socket.send(new Buffer(REQ), 0, REQ.length, broadcastPort, broadcastAddress, function (err) {
						if (err) console.log(err);
						//console.log("Broadcast message sent");
					});



	this.on('newListener', function(listener) {
	});
	
	setTimeout(function(){
		socket.close();
		that.emit("devices",devices);
		return 0; //close the function
	}, timeout);
};
util.inherits(detection , EventEmitter);
module.exports = detection;