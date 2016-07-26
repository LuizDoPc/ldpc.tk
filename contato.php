<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8"/>
    <title>Home</title>
    <link rel="stylesheet" href="css/contato.css">
</head>
<body>
<h1 id="title">Envie sua sugestão para nós!</h1>

<a href="index.html">
                <div class="item" align="center">
                    <span class="txtitem">Home</span>
                </div>
</a>

<div id="form">
    <form id="contato" method="get" action="php/contato.php">
        <div class="in">Nome<br>
        <input type="text" id="nome" name="nome" required placeholder="Digite seu nome"/></div>

        <div class="in">Email<br>
        <input type="email" id="email" name="email" required placeholder="Digite seu email de contato"/><br/></div>

        <div class="su"><br>Sugestão<br></div>
        <textarea typeof="text" id="sugest" name="sugest" required placeholder="Digite sua sugestão"></textarea><br/>

        <div class="su"><input type="submit" id="sub" name="sub" value="Enviar"/></div>

    </form>
</div>

<div id="resto">
    <?php
            $msg=$_GET["msg"];
            if($msg=='1'){
                ?>
                <figure>
                    <img src="img/check-button.png" style="margin-top: 100px"/>
                    <figcaption>Mensagem enviada com sucesso!</figcaption>
                </figure>
                <?php
            }
            else{
            ?>
                <figure>
                    <img src="img/lampada.png" style="margin-top: 100px"/>
                    <figcaption>Ideias? Conta pra gente!</figcaption>
                </figure>
                <?php
                }
             ?>
</div>

</body>