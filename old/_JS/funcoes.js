//vaca
function mostra(){
    document.getElementById("vaca").src="../_IMG/vaca.jpeg";
    setTimeout('repoe()', 2000);
}
var mat;
function repoe(){
    document.getElementById("vaca").src="../_IMG/branco.jpg";
    setTimeout(2000);
    mat=Math.floor(Math.random() * (800 - 1)) + 1;
    document.getElementById("vaca").style.marginBottom=mat+"px";
    document.getElementById("vaca").style.marginTop=mat+"px";
    document.getElementById("vaca").style.marginLeft=mat+"px";
    mat=0;
}

//lampada
function test(type) {
    if(type==1){
        document.getElementById("lampada").src="_IMG/lampada-quebrada.jpg";
    }
    var srrc = type.getAttribute("src");
    if (srrc=="_IMG/lampada-apagada.jpg"){
        document.getElementById("lampada").src="_IMG/lampada-acesa.jpg";
    }
    else if (srrc=="_IMG/lampada-acesa.jpg"){
        document.getElementById("lampada").src="_IMG/lampada-apagada.jpg";
    }
    if(type==1){
        document.getElementById("lampada").src="_IMG/lampada-quebrada.jpg";
    }
}