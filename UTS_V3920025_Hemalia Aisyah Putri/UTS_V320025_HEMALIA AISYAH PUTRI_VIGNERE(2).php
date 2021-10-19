<?php

// Fungsi untuk mengenkripsikan variabel
function Encipher($pswd, $variabel)
{
	// strtolower berfungsi untuk mengonversikan key ke huruf kecil
	$pswd = strtolower($pswd); 
	
	// menginisialisasi variabel
	$code = "";
	$ki = 0;
	$kl = strlen($pswd); //strlen berfungsi untuk menghitung jumlah karakter pada pswd
	$length = strlen($variabel);//strlen berfungsi untuk menghitung jumlah karakter pada variabel
	
	// Membuat perulangan menggunakan for
	for ($i = 0; $i < $length; $i++)
	{
		// jika $variabel merupakan angka maka akan di encrypt
		if (ctype_alpha($variabel[$i]))
		{
			// uppercase
			if (ctype_upper($variabel[$i]))
			{
				$variabel[$i] = chr(((ord($pswd[$ki]) - ord("a") + ord($variabel[$i]) - ord("A")) % 26) + ord("A"));
			}
			
			// lowercase
			else
			{
				$variabel[$i] = chr(((ord($pswd[$ki]) - ord("a") + ord($variabel[$i]) - ord("a")) % 26) + ord("a"));
			}
			
			// mengupdate index key nya
			$ki++;
			if ($ki >= $kl)
			{
				$ki = 0;
			}
		}
	}
	
	// mengembalikan nilai $variabel
	return $variabel;
}

// fungsi untuk mendeskripsikan variabel
function Decipher($pswd, $variabel){
	// mengonversikan key ke huruf kecil
	$pswd = strtolower($pswd);
	
	// inisialisasi variabel
	$code = "";
	$ki = 0;
	$kl = strlen($pswd);
	$length = strlen($variabel);
	
	// membuat perulangan menggunakan for
	for ($i = 0; $i < $length; $i++)
	{
		// jika $variabel merupakan abjad maka akan di encrypt
		if (ctype_alpha($variabel[$i]))
		{
			// uppercase
			if (ctype_upper($variabel[$i]))
			{
				$x = (ord($variabel[$i]) - ord("A")) - (ord($pswd[$ki]) - ord("a"));
				
				if ($x < 0)
				{
					$x += 26;
				}
				
				$x = $x + ord("A");
				
				$variabel[$i] = chr($x);
			}
			
			// lowercase
			else
			{
				$x = (ord($variabel[$i]) - ord("a")) - (ord($pswd[$ki]) - ord("a"));
				
				if ($x < 0)
				{
					$x += 26;
				}
				
				$x = $x + ord("a");
				
				$variabel[$i] = chr($x);
			}
			
			// mengupdate index key nya
			$ki++;
			if ($ki >= $kl)
			{
				$ki = 0;
			}
		}
	}
	
	// mengembalikan nilai
	return $variabel;
}

?>