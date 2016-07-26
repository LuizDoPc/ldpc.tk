<?php


if (!empty($_SERVER['HTTP_CLIENT_IP']))
    {

        $ip = $_SERVER['HTTP_CLIENT_IP'];

    }
    elseif (!empty($_SERVER['HTTP_X_FORWARDED_FOR']))
    {

        $ip = $_SERVER['HTTP_X_FORWARDED_FOR'];

    }
    else{

        $ip = $_SERVER['REMOTE_ADDR'];

    }

    $email=$_GET["email"];
    $nome=$_GET["nome"];
    $sugest=$_GET["sugest"];
    $dest='luizotavioasoares@gmail.com';
    $assunto='Sugestao LDPC';
    $mensagem="$nome sugeriu: $sugest. Seu e-mail de contato e $email. Seu ip é: $ip. Versão antiga.";
    $cabecalho='FROM:contato@ldpc.tk';
    mail($dest,$assunto,$mensagem,$cabecalho);
    header("location:../contato.php?msg=1");
?>