
var MesageName = 'editor';

/*
$(document).ready(function(){
   onload();
});

function onload(){
	init();
	newBtn = document.getElementById("new");
	openBtn = document.getElementById("open");
	saveBtn = document.getElementById("save");

	newBtn.addEventListener("click", onNewButon);
	openBtn.addEventListener("click", onOpenButon);
	saveBtn.addEventListener("click", onSaveButon);
};

function init(){
	
}*/

function onNewButon(){
	var x = window.screenX + 10;
	var y = window.screenY + 10;
	window.open('editor.html', '_blank', 'screenX=' + x + ',screenY=' + y);
}

function onOpenButon(){
	alert("onOpenButon");
	var message = MesageName+'.'+"FileOpen";
	app.setMessageCallback(message, function(name, args){
		document.getElementById("result").value = args[0];
		app.removeMessageCallback(message);
	})
	
	app.sendMessage(message);
	
}

function onSaveButon(){
	alert("onSaveButon");
}