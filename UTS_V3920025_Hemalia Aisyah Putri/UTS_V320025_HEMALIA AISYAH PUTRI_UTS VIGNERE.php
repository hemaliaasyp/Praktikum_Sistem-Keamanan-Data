<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">

	<title>VIGENEREI CIPHER</title> 

    <link href="assets/bootstrap/css/bootstrap.min.css" rel="stylesheet">
     <meta charset="utf-8">
  
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KyZXEAg3QhqLMpG8r+8fhAXLRk2vvoC2f3B09zVXn8CA5QIVfZOJ3BCsw2P0p/We" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="index.css">

    <!-- Google Font -->
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600,700,300italic,400italic,600italic">

</head>
<body>
	<div class="container">
		<h2 class="text-center">VIGENEREI CIPHER</h2> <!--menampilkan judul pada tengah-->
		<?php
        // menginisialisasi variabel
        $pswd = "";
        $code = "";
        $error = "";
        $valid = true;
        $color = "#FF0000";

        // pengkondisian setelah submit dengan method post
        if ($_SERVER['REQUEST_METHOD'] == "POST"){
            // mendeklarasikan fungsi encrypt dan decrypt yang mana berada di vigenere.php dan dipanggil dengan require_once
            require_once('vigenere.php');
    
            // mengeset variabel
            $pswd = $_POST['pswd'];
            $code = $_POST['code'];
    
            //mengecek jika pswd atau key kosong maka akan dijalankan text error dan tidak valid
            if (empty($_POST['pswd'])){
                $error = "Silakan masukkan kata sandi!";
                $valid = false;
            }
    
            // mengecek jika text kosong maka akan dijalankan text error dan tidak valid
            else if (empty($_POST['code'])){
                $error = "Silakan masukkan beberapa teks atau kode untuk mengenkripsi atau mendekripsi!";
                $valid = false;
            }
    
            //mengecek jika terdapat alphanumeric/kombinasi angka dan huruf pada pswd/key maka akan dijalankan text error dan tidak valid 
            else if (isset($_POST['pswd'])){
                if (!ctype_alpha($_POST['pswd'])){
                    $error = "Kata sandi hanya boleh berisi karakter alfabet!";
                    $valid = false;
                }
            }
    
            // menginputkan yang valid
            if ($valid){
                // jika button encrypt  diklik maka akan dijalankan fungsi Encipher dan dimunculkan pesan sukses
                if (isset($_POST['encrypt'])){
                    $code = Encipher($pswd, $code);
                    $error = "Text Enkripsi Sukses!";
                    $color = "	#000000";
                }
            
                // jika button decrypt diklik maka akan dijalankan fungsi Decipher dan dimunculkan pesan sukses
                if (isset($_POST['decrypt'])){
                    $code = Decipher($pswd, $code);
                    $error = "Kode Deskripsi Sukses!";
                    $color = "	#000000";
                }
            }
        }

        ?>

		<form action="utsvignere.php" method="post"> <!--memiliki nama enkripsi dan method post-->
			<div class="form-group">
                <label>Isi Kunci</label> <!--menampilkan label-->
                <input title="Pilih Key." required="true" oninvalid="this.setCustomValidity('Tidak boleh kosong!')" oninput="setCustomValidity('')" type="text" class="form-control" name="pswd" id="pass" placeholder="Masukan Key"> <!--memiliki required yg berarti harus diisi/tidak boleh kosong -->
                <label>Isi Text</label><!--menampilkan label-->
				<textarea name="code" required="true" oninvalid="this.setCustomValidity('Tidak boleh kosong!')" oninput="setCustomValidity('')"  class="form-control" rows="3" placeholder="Isikan teks disini"></textarea>  <!--memiliki required yg berarti harus diisi/tidak boleh kosong -->
			</div>
			<div class="box-footer">
                <table class="table table-stripped">
                    <tr>
                    <td><input type="submit" name="encrypt" value="Enkripsi" style="width: 100%" onclick="validate(1)"></td> <!--memiliki button yg memiliki nama encrypt yang akan dihubungkan pada php yg diatas-->
                    <td><input type="submit" name="decrypt" value="Deskripsi" style="width: 100%" onclick="validate(2)"></td><!--memiliki button yg memiliki nama decrypt yang akan dihubungkan pada php yg diatas-->
                    </tr>
                </table>
            </div>
                <tr>
                    <td><center><div style="color: <?php echo htmlspecialchars($color) ?>"><?php echo htmlspecialchars($error) ?></div></center></td> <!--mengambil warna dari htmlspecialchars($color), yang $color nya sudah diinisialiasi diatas dan menggunakan htmlspecialchars($error)-->
                </tr>
        </form>
				<div class="box-body">
        		<label>Hasil</label> <!--menampilkan hasil-->
          			<table class="table table-bordered">
            			<tr style="background-color:#FF00FF"><!--menampilkan warna background-->
              				<td style="text-align:center"><b>
                		      <?php echo htmlspecialchars($code); ?> <!--menggunakan karakter spesial-->
              				</b></td>
            			</tr>
          			</table>
            				</tr>
          				</table>
          				<br>
          				<br>
      
    					<br>
    				</div>
		</form>
		</div>
	</div>
</body>

<script src="assets/jquery.min.js"></script> 
<script src="assets/bootstrap/js/bootstrap.min.js"></script> 
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.0/dist/js/bootstrap.bundle.min.js" integrity=" sha384-U1DAWAznBHeqEIlVSCgzq+c9gqGAJn5c/t99JyeKa9xxaYpSvHU5awsuZVVFIhvj" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.3/dist/umd/popper.min.js" integrity="sha384-eMNCOe7tC1doHpGoWe/6oMVemdAVTMs2xqW4mwXrXsW0L84Iytr2wi5v2QjrP/xp" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.0/dist/js/bootstrap.min.js" integrity="sha384-cn7l7gDp0eyniUwwAZgrzD06kc/tftFf19TOAs2zVinnD/C7E91j9yyk5//jjpt/" crossorigin="anonymous"></script>  
</script>
</html>