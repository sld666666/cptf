
var MesageName = "Editor";


$(document).ready(function(){
   onload();
   initEvent();
});

function initEvent(){
	$("#code").on('change keyup paste', function(){
		reload();
	});
}

function onload(){
	reload();
};

function reload(){
	var value = $('#code').val();
	setOutput(value);
}

function setOutput(value){
	document.getElementById("out").innerHTML = marked(value);
}