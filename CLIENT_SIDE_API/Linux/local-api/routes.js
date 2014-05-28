/**
 * @author jimmy
 */

// Load the route handlers
var detection_module = require('./detection_module_handlers');

module.exports = function(server) {

  // Define the routes
	// detection module
	server.get('/where_is_my_tool', detection_module.where_is_my_tool);
	server.get(/^\/are_you_a_sbt\/((?:\d{1,3}\.){3}\d{1,3})$/, detection_module.are_you_a_sbt);
	server.get('/detection_tool', detection_module.local_detection);

};