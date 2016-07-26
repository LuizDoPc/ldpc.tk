<!DOCTYPE html>
    <html lang="pt-br">

<head>
<?php
$host = "mysql.hostinger.com.br";
$user = "u769511604_ldpc";
$pass = "l411993210";
$banco = "u769511604_as";
$conexao = mysql_connect($host, $user, $pass) or die (mysql_error());
mysql_select_db($banco) or die(mysql_error());
?>
<title>Auth</title>
<script type="text/javascript">
    function ls(){
        setTimeout("window.location='video.html'",10);

    }

    function lf(){
        setTimeout("window.location='index.php'",10);
    }
</script>

</head>
<body>

<?php
    $senha = $_POST['senha'];
    $sql = mysql_query("SELECT * FROM senhas WHERE senha = '$senha'") or die(mysql_error());
    $row = mysql_num_rows($sql);
    if($row > 0){
        session_start();
        $_SESSION['senha'] = $_POST['senha'];
        echo"<script>ls()</script>";

    }else{
        echo"<script>lf()</script>";
    }

?>

</body>
</html>