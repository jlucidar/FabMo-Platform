// JavaScript Document
$(function(){ //docready


		// Hover: callbacks for star selection effects
		$(".star-box a").hover(function(){
			$(this).prevAll().andSelf()
			.removeClass("icon-star-empty")
			.addClass("icon-star")
			.css("color","#fbce29");
		},
		function() {
			refresh_stars();
		});

		// Click: set rank value
		$(".star-box a").click(function(){
			$("#rank").val($(this).index()+1);
			refresh_stars();
		});

	
	
	
	
	

	// link functionality for idea boxes
	$("#idea_container .box").click(function() {
		location.href = "app-detail.php?id=" + $(this).attr("data-id");
	});



		
	$("#idea_container .box").click(function() {
		location.href = "app-detail.php?idea=" + $(this).attr("data-id");
	});
	
});

// Rating submit by ajax
function rating_box_form_submit() {	
	//event.preventDefault();
	rating_form = $("#rating_box_form").serialize();
	// Sends form data to 'proc/insert_rating_proc.php' which uses 'func_insertAppIdeaRank' 
	$.ajax({
		  type: "POST",
		  url: "proc/idea_rate_proc.php",
		  data: rating_form,
		  success: function(data) {			  	
			if(data == "0") {
				sgGetAppIdeaComments($('#comment_appIdeaId').val());
				$("#comment_rating_success h5").text("Thanks! Your rating and comment have been submitted.");					
			}
			else {
				$("#comment_rating_success h5").text("Sorry. There was a problem submitting your rating.")
			}
			$("#comment_rating_success").foundation('reveal', 'open');

		  }
		});
	return false;
}


// Idea Comment submit by ajax
function comment_box_form_submit() {
	  	//event.preventDefault();
	  	comment_form = $("#comment_box_form").serialize();
	  	// Sends form data to 'proc/insert_rating_proc.php' which uses 'func_insertAppIdeaRank' 
	  	$.ajax({
			  type: "POST",
			  url: "proc/idea_comment_proc.php",
			  data: comment_form,
			  success: function(data) {			  	
				if(data == "0") {
			  		//$("#comment_success h5").text("Thanks! Your rating and comment have been submitted.");
					sgGetAppIdeaComments($('#comment_appIdeaId').val());
					$("#comment").val('');
			  	}
			  	else {
			  		$("#comment_success h5").text("Sorry. There was a problem submitting your comment.");
					$("#comment_success").foundation('reveal', 'open');
			  	}
			  }
			});
	  	return false;
}


function frm_idea_1_submit() {
	// do other stuff for a valid form										
	//alert('hey');				
	$('#idea_submit_1_message').html('Please Wait...');	
	$.post('proc/idea_submit_1_proc.php', $("#frm_idea_1").serialize(), function(data) {				
		//alert('hey');									
		$('#idea_submit_1_message').html(data);				
	});								
	$("#idea_submit_1_message").trigger("create");
}

function frm_idea_2_submit() {
	// do other stuff for a valid form										
	//alert('hey');				
	$('#idea_submit_2_message').html('Please Wait...');	
	$.post('proc/idea_submit_2_proc.php', $("#frm_idea_2").serialize(), function(data) {				
		//alert('hey');									
		$('#idea_submit_2_message').html(data);
	});								
	$("#idea_submit_2_message").trigger("create");	
}

function frm_idea_url_submit() {
	//alert('hey');				
	$('#idea_submit_url_message').html('Please Wait...');	
	$.post('proc/idea_submit_url_proc.php', $("#frm_idea_url").serialize(), function(data) {				
		//alert('hey');									
		$('#idea_submit_url_message').html(data);		
	});								
	$("#idea_submit_url_message").trigger("create");	
}




function comment_edit(var_id){
	//alert(var_id);
	$(this['comment_'+var_id]).hide();
	$(this['comment_edit_'+var_id]).show();
}

function comment_edit_cancel(var_id){
	//alert(var_id);
	$(this['comment_'+var_id]).show();
	$(this['comment_edit_'+var_id]).hide();
}

function comment_delete(var_id){
	var resultOfConfirm = confirm("Are you sure you want to delete this comment?");
	if (resultOfConfirm == true) {		
		//document.body.style.cursor = "wait";
		//document.location.href='proc/idea_submit_url_delete_proc.php?appIdeaId='+appIdeaId+"&id="+id;	
		$.ajax({
			  type: "POST",
			  url: "proc/idea_comment_delete_proc.php",
			  data: {comment_id: var_id},		
			  success: function(data) {			  	
				if(data == "0") {
			  		//$("#comment_success h5").text("Thanks! Your rating and comment have been submitted.");
					sgGetAppIdeaComments($('#comment_appIdeaId').val());
			  	}
			  	else {
			  		//alert(data);
					$("#comment_success h5").text("Sorry. There was a problem deleting comment.");
					$("#comment_success").foundation('reveal', 'open');
			  	}
			  }
			});	
	}
}

function comment_update(var_id){
	$.ajax({
		  type: "POST",
		  url: "proc/idea_comment_update_proc.php",
		  data: {	comment_id:var_id,
		  			comment:$(this['comment_text_'+var_id]).val()},		
		  success: function(data) {			  	
			if(data == "0") {
				//$("#comment_success h5").text("Thanks! Your rating and comment have been submitted.");
				sgGetAppIdeaComments($('#comment_appIdeaId').val());
			}
			else {
				//alert(data);
				$("#comment_success h5").text("Sorry. There was a problem deleting comment.");
				$("#comment_success").foundation('reveal', 'open');
			}
		  }
		});	
}


// Turns stars yellow based on rank in hidden #rank field
function refresh_stars() {
	$.each($(".star-box a"), function() {
				if (parseInt($(this).index())+1 > parseInt($("#rank").val())) {
					$(this).removeClass("icon-star")
					.addClass("icon-star-empty")
					.css("color","gray");
				}
			})
}



function record_rank(var_rank) {
	$('#rank').val(var_rank);	
	//rank_recorded = true;	
}


function confirm_appIdea_delete(var_id){
	var resultOfConfirm = confirm("Are you sure you want to delete this App Idea?");
	if (resultOfConfirm == true) {		
		//document.body.style.cursor = "wait";
		//document.location.href='proc/idea_submit_url_delete_proc.php?appIdeaId='+appIdeaId+"&id="+id;	
		$.ajax({
			  type: "POST",
			  url: "proc/idea_delete_proc.php",
			  data: {appIdeaId: var_id},		
			  success: function(data) {			  	
				if(data == "0") {
					document.location.href='handibot-apps.php';
			  	}
			  	else {
			  		alert(data);
			  	}
			  }
			});	
	}
}


