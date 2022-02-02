<?php
/** 
 * Comentário de cabeçalho operadores.php
 * Definir aqui a função designada a esse arquivo
 *
 *
 * @autor   	Leandro Jorge Junges <analista@cotrirosa.com.br> 
 * @versão  	0.1 
 * @licença 	Todos Direitos Reservados a Cotrirosa Copyright © 2017
 * @empresa 	Cooperativa Tritícola Santa Rosa Ltda - Cotrirosa 
 * @setor   	Departamento de Tecnologia da Informação
 * @acesso  	público 
 * @codificação UTF-8
 * @linguagem   PHP - PT/BR
 * @criação     5 de jun de 2017 - 11:10:15
 * @local       \
 */
?>

<!DOCTYPE HTML>
<html lang="pt-br">
    <head>
    	<meta http-equiv="Content-Language" content="pt-br">
    	<meta charset="utf-8">
    	<title>Primeiro Texto</title>
    	<link rel="icon" href="img/icopag.ico" type="image/x-icon" />
    	<link rel="shortcut icon" href="img/icopag.ico" type="image/x-icon" />
  		<link rel="stylesheet" href="../_css/estilo.css"/>
    </head>
    <body>
    <div>
    <?php
        $n1 = $_GET["a"];    
        $n2 = $_GET["b"]; 
        $m = ($n1 + $n2) / 2;
        
        echo "<h2>Valores Recebidos: $n1 e $n2</h2>";
        
        echo "A soma vale " . ($n1 + $n2);
        echo "<br/>A subtração vale  " . ($n1 - $n2);
        echo "<br/>A multiplicação vale  " . ($n1 * $n2);
        echo "<br/>A divisão vale  " . ($n1 / $n2);
        echo "<br/>O módulo vale  " . ($n1 % $n2);
        echo "<br/>A média vale  " . $m;
	?>
	</div>
    </body>
</html>