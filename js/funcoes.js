//vaca
function mostra(){
    document.getElementById("vaca").src="img/vaca.jpeg";
    setTimeout('repoe()', 2000);
}
var mat;
function repoe(){
    document.getElementById("vaca").src="img/branco.jpg";
    setTimeout(2000);
    mat=Math.floor(Math.random() * (800 - 1)) + 1;
    document.getElementById("vaca").style.marginBottom=mat+"px";
    document.getElementById("vaca").style.marginTop=mat+"px";
    document.getElementById("vaca").style.marginLeft=mat+"px";
    mat=0;
}
