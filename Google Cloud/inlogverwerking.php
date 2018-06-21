<?php
session_start();
 if (!isset($_SESSION['ingelogd'])) {
    $_SESSION['ingelogd'] = false;
	}
    if (isset($_POST['wachtwoord'])) {
    $sWachtwoord = $_POST['wachtwoord'];
	}
	if (!isset($_SESSION['teller'])) {
    $_SESSION['teller'] = 0;
	}

if (isset($_POST['gebruikersnaam'])) {
    $sGebruikersnaam = $_POST['gebruikersnaam'];
}
//	$_SESSION['gebruikersnaam']= $_POST['gebruikersnaam'];
//	$_SESSION['wachtwoord']= $_POST['wachtwoord'];
	if ($_SESSION['teller'] > 2){
			header ('Location: wwtevaak.html');	
		}
		else{
	if($sWachtwoord == 'informatica')
		{
			$_SESSION['ingelogd']= true;
			$_SESSION['teller'] = 0;
			header ('Location: inde.php');	
			
		}
		else
		{
			
			$_SESSION['teller']=$_SESSION['teller']+1;
			$_SESSION['ingelogd']= false;
			header ('Location: inlog.php');	
		}
		}

?>

