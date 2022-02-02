<?php $selAre = isset($_POST["fileToUpload"])?$_POST["fileToUpload"]:-1; ?>


<!DOCTYPE html>
<html>
	<body>

	<form id='dados' method='post' name="form" action='<?php $_SERVER['PHP_SELF'] ?>'  enctype="multipart/form-data"   >
		Select image to upload:
		<input type="file" name="fileToUpload" id="fileToUpload"></br>		
		<input type='submit' id='idSubmit' class='button' value='Salvar' name='OK' onClick=\"LOAD=0;\">
	</form>

	</body>
</html>

<?php

	if (isset($_POST['OK']) && $_FILES["fileToUpload"]["name"] <> ''){
		
		$tmp_cod = rand(100,999);
		$target_dir = "uploads/tmp_".$tmp_cod;
		
		while (is_dir($target_dir)){
			$tmp_cod = rand(100,999);
			$target_dir = "uploads/tmp_".$tmp_cod;
		}
		
		mkdir($target_dir, 0777, true);
		
		
		
		
		$target_dir .= "/";
		
		
		echo $target_file;
		
		$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
		$uploadOk = 1;
		$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
		// Check if image file is a actual image or fake image
		/*
		if(isset($_POST["submit"])) {
			$check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
			if($check !== false) {
				echo "File is an image - " . $check["mime"] . ".";
				$uploadOk = 1;
			} else {
				echo "File is not an image.";
				$uploadOk = 0;
			}
		}
		*/
		// Check if file already exists
		if (file_exists($target_file)) {
			echo "Sorry, file already exists.";
			$uploadOk = 0;
		}
		// Check file size
		if ($_FILES["fileToUpload"]["size"] > 50000000000000000000000000000) {
			echo "Sorry, your file is too large.";
			$uploadOk = 0;
		}
		// Allow certain file formats
		/*
		if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
		&& $imageFileType != "gif" ) {
			echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
			$uploadOk = 0;
		}
		*/
		// Check if $uploadOk is set to 0 by an error
		if ($uploadOk == 0) {
			echo "Sorry, your file was not uploaded.";
		// if everything is ok, try to upload file
		} else {
			$filInp=$_FILES["fileToUpload"]['tmp_name'];
			$tamImg = getimagesize($filInp);
			$tamArq = filesize($filInp);
			
			if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
				echo "The file ". basename( $_FILES["fileToUpload"]["name"]). "</br></br>";
				
				echo "<span>Nome:</span> <input value='". $_FILES["fileToUpload"]['name']. "'></br> 
					  <span>Tipo:</span> <input value='". $_FILES["fileToUpload"]['type']. "'></br> 
					  <span>Local:</span> <input value='". $target_file . "'></br> 
					  <span>Largura:</span> <input value='".$tamImg[0]. "'></br> 
					  <span>Altura:</span> <input value='".$tamImg[1]. "'></br> 
					  <span>Tamanho:</span> <input value='".$tamArq . "'></br>";
				
				
				
				
			} else {
				echo "Sorry, there was an error uploading your file.";
			}
		}
		
	}
	$target_dir = "uploads/tmp_".$tmp_cod;
		
	
	//deletar arquivos e Diretórios
	$path = 'uploads';
	if ($handle = opendir($path)) {
		
		while (false !== ($filename = readdir($handle))) { 
			$dirScan = $path .'/'. $filename;
			$stat = stat($dirScan);
			//24 hours in a day * 3600 seconds per hour
			//if((time() - $filelastmodified) > 24*3600)
			if(((time() - $stat['mtime']) > 60) && (substr_count($dirScan, 'tmp') > 0)){	
				echo $dirScan.";";
				
				foreach (scandir($dirScan) as $file) {
					if ($item != '.' && $item != '..') {
						unlink( $dirScan ."/". $file );
					}
				}
				
				rmdir($dirScan);
			}
			
		}

		closedir($handle); 
	}
?>