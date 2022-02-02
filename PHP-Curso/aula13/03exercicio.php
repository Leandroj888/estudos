<?php
/** 
 * Comentário de cabeçalho 01dados.php
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
 * @criação     6 de jun de 2017 - 09:45:23
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
        $n = isset($_GET["v1"])?$_GET["v1"]:0;
       
        $mul= "";
        $tmu= 0;
        for($x=1; $x <= $n; $x++){
            if($n % $x == 0){
                $tmu++;
                $mul .= "$x ";
            }            
        }
        
        echo "<h1> O número processado foi $n </h1> <br/><br/>"; 
        echo "Valores Múltiplos: $mul <br/> "; 
        echo "Total de Múltiplos: $tmu <br/><br/> ";
        
        if($tmu == 2)
            echo "Rsultado: $n <span style='color:green;'>é primo<span><br/>";
        else 
            echo "Rsultado: $n <span style='color:red;'>não é primo<span><br/>";
        
	?>
	<a href="javascript:history.go(-1)" class="botao">Voltar</a>
	</div>
    </body>
</html>