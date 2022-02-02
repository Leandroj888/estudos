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
		<?php
            $tex = isset($_GET["t"])?$_GET["t"]:"Texto Genérico";
            $tam = isset($_GET["tam"])?$_GET["tam"]:"12pt";
            $cor = isset($_GET["cor"])?$_GET["cor"]:"#000000";
        ?>
	
		<meta http-equiv="Content-Language" content="pt-br">
		<meta charset="utf-8">
		<title>Primeiro Texto</title>
		<link rel="icon" href="img/icopag.ico" type="image/x-icon" />
		<link rel="shortcut icon" href="img/icopag.ico" type="image/x-icon" />
  		<link rel="stylesheet" href="../_css/estilo.css"/>
        <style>
            span.texto {
                color:<?php echo $cor; ?>;
                font-size:<?php echo $tam; ?>;
            }
       </style>     
	</head>
    <body>
    <div>
    <?php        
        echo "<span class='texto'>$tex</span>";
	?>
	<br/><br/>
	<a href="03exercicio.html">Voltar</a>
	</div>
    </body>
</html>