//var surl =  "http://localhost/handibot/ajax_proc/";
var surl =  "http://handibot.com/ajax_proc/";

function sgGetAppIdeaLinks(appIdeaId) {
	$.ajax({
		url: surl + 'getAppIdeaLinks.php',		
		data: {appIdeaId: appIdeaId},		
		//data: {},
		dataType: "jsonp",
		jsonp : "callback",
		jsonpCallback: "jsonpcallbackGetAppIdeaLinks"
	});	
}

function sgGetAppIdeaFiles(appIdeaId) {
	$.ajax({
		url: surl + 'getAppIdeaFiles.php',		
		data: {appIdeaId: appIdeaId},		
		//data: {},
		dataType: "jsonp",
		jsonp : "callback",
		jsonpCallback: "jsonpcallbackGetAppIdeaFiles"
	});	
}

function sgGetAppIdeaFilesDetail(appIdeaId) {
	$.ajax({
		url: surl + 'getAppIdeaFiles.php',		
		data: {appIdeaId: appIdeaId},		
		//data: {},
		dataType: "jsonp",
		jsonp : "callback",
		jsonpCallback: "jsonpcallbackGetAppIdeaFilesDetail"
	});	
}

function sgGetAppIdeaComments(appIdeaId) {
	$.ajax({
		url: surl + 'getAppIdeaComments.php',		
		data: {appIdeaId: appIdeaId},		
		//data: {},
		dataType: "jsonp",
		jsonp : "callback",
		jsonpCallback: "jsonpcallbackGetAppIdeaComments"
	});	
}


function sgPSLogin(email,passwd,goto) {		
	$.ajax({
	  type: "POST",
	  url: "https://handibot.com/store/index.php?controller=authentication",
	  data: {email:email,passwd:passwd,back:"my-account",SubmitLogin:'Authentication'},
	  success: function(data) {			  		  
		console.log(data);		
		/*$.ajax({
		   url: "dozuki/addUser.php"
		}).done(function(response) {
		   console.log(response);
		});
		*/					
		if(goto == '') {
			document.location.reload();	
		} else {
			document.location.href= goto;	
		}
		
		
	  }
	});
	/*
	if(goto == '') {
		document.location.reload();	
	} else {
		document.location.href= goto;	
	}
	*/
}