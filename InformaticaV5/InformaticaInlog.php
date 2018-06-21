<<<<<<< HEAD
﻿<?php
session_start();
 if (!isset($_SESSION['ingelogd'])) {
    $_SESSION['ingelogd'] = false;
	}
	
    $sWachtwoord = 'nul';
	
    if (isset($_POST['wachtwoord'])) {
    $sWachtwoord = $_POST['wachtwoord'];
	}

if (isset($_POST['gebruikersnaam'])) {
    $sGebruikersnaam = $_POST['gebruikersnaam'];
}



	$md5Str = md5('informatica');
//	if($sWachtwoord == $md5Str)
	if ($sWachtwoord == $md5Str)
		{
			echo 'goed';
			
		}
		else
		{
			
			echo 'fout';
		}
		

?>

=======
﻿<?php
session_start();
 if (!isset($_SESSION['ingelogd'])) {
    $_SESSION['ingelogd'] = false;
	}
	
    $sWachtwoord = 'nul';
	
    if (isset($_POST['wachtwoord'])) {
    $sWachtwoord = $_POST['wachtwoord'];
	}

if (isset($_POST['gebruikersnaam'])) {
    $sGebruikersnaam = $_POST['gebruikersnaam'];
}



	$md5Str = md5('informatica');
//	if($sWachtwoord == $md5Str)
	if ($sWachtwoord == $md5Str)
		{
			echo 'goed';
			
		}
		else
		{
			
			echo 'fout';
		}
		

?>

>>>>>>> origin/master
