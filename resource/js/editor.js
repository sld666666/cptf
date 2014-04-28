
$(document).ready(function(){
   onload();
});

function onload(){
	newBtn = document.getElementById("new");
	openBtn = document.getElementById("open");
	saveBtn = document.getElementById("save");

	newBtn.addEventListener("click", onNewButon);
	openBtn.addEventListener("click", onOpenButon);
	saveBtn.addEventListener("click", onSaveButon);
};

function initContextMenu(){

}

function onNewButon(){
	var x = window.screenX + 10;
	var y = window.screenY + 10;
	window.open('editor.html', '_blank', 'screenX=' + x + ',screenY=' + y);
}

function onOpenButon(){
	alert("onOpenButon");
}

function onSaveButon(){
	alert("onSaveButon");
}