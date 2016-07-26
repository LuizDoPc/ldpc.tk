<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8"/>
    <title>Home</title>
    <link rel="stylesheet" href="_CSS/estilo.css"/>
    <link rel="stylesheet" href="_CSS/contato.css"/>
</head>
<body>
<nav id="menu">
    <ul type="none">
        <li><a href="index.html">Home</a></li>
        <li><a href="segredo.html">Segredo</a></li>
        <li><a href="js.html">Lampada</a></li>
        <li><a href="vaca">Ache a vaca</a></li>
        <li><a href="about.html">Sobre mim</a></li>
        <li><a href="contato.php">Fale Conosco!</a></li>
    </ul>
</nav>

    <h1 id="title">Envie sua sugestão para nós!</h1>
    <div id="form">
        <form id="contato" method="get" action="_PHP/contato.php">

            Nome<br>
            <input type="text" id="nome" name="nome" required placeholder="Digite seu nome"/><br/>

            Email<br>
            <input type="email" id="email" name="email" required placeholder="Digite seu email de contato"/><br/>

            Sugestão<br>
            <textarea typeof="text" id="sugest" name="sugest" cols="41" rows="20" placeholder="Digite sua sugestão"></textarea><br/>

            <input type="submit" id="sub" name="sub" value="Enviar"/>

        </form>
    </div>

    <div id="resto">
        <img src="_IMG/homem-contato.png" id="image">
        <?php
            $msg=$_GET["msg"];
            if($msg=='1'){
            ?>
                <figure>
                    <img src="_IMG/check-button.png" style="margin-top: 100px"/>
                    <figcaption>Mensagem enviada com sucesso!</figcaption>
                </figure>
                <?php
            }
        ?>
    </div>

</body>