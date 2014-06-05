
var MesageName = "Editor";
var flag = 0 ;

$(document).ready(function(){
   onload();
   initEvent();
   $("#menu").menu({position: {at: "left bottom"}});
});

function initEvent(){
	$("#code").keydown(function(event){
		keypressEvent(event);
	});
	
	$("#code").on('change keyup paste', function(){
		reload();
	});
	
	$("#file_open").click(function(){
		openFile();
	});
	
	$("#file_save").click(function(){
		saveFile();
	});
	
	$("#file_new").click(function(){
		newFile();
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

function openFile(){
	alert("open");
}

function saveFile(){
	alert("save");
}

function newFile(){
	alert("new");
}

function keypressEvent(keyEvent){
	if(1== flag)
		var test = 0;
	if(keyEvent.ctrlKey){
		
		if(keyEvent.keyCode == 78){
			newFile();
		}else if(keyEvent.keyCode == 83){
			saveFile();
		}else if(keyEvent.keyCode == 79){
			openFile();
		}else if(keyEvent.keyCode == 89){
			alert("y");
		}
		
		flag = 1;
	}else{
		keyEvent.preventDefault();   
	}
	
}