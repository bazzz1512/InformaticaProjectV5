<?php
session_start();
		$iAantalproduct1= $_GET['AC4Amount'];
		$_SESSION['aantalproduct1']= $iAantalproduct1 ;
		$iAantalproduct2= $_GET['ACSAmount'];
		$_SESSION['aantalproduct2']= $iAantalproduct2 ;
		$iAantalproduct3= $_GET['CSGOAcount'];
		$_SESSION['aantalproduct3']= $iAantalproduct3 ;
		$iAantalproduct4= $_GET['CSSAmount'];
		$_SESSION['aantalproduct4']= $iAantalproduct4 ;
		$iAantalproduct5= $_GET['CODGAmount'];
		$_SESSION['aantalproduct5']= $iAantalproduct5 ;
		$iAantalproduct6= $_GET['CODAWAmount'];
		$_SESSION['aantalproduct6']= $iAantalproduct6 ;
		header ('Location: bestellingzien.php');

?>

