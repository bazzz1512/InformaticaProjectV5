<?php 
session_start();
	$_SESSION['prijsproduct1']=10* $_SESSION['aantalproduct1'];
	$_SESSION['prijsproduct2']=20* $_SESSION['aantalproduct2'];
	$_SESSION['prijsproduct3']=30* $_SESSION['aantalproduct3'];
	$_SESSION['prijsproduct4']=40* $_SESSION['aantalproduct4'];
	$_SESSION['prijsproduct5']=50* $_SESSION['aantalproduct5'];
	$_SESSION['prijsproduct6']=60* $_SESSION['aantalproduct6'];
	$_SESSION['somproducten']= $_SESSION['prijsproduct1']+$_SESSION['prijsproduct2']+$_SESSION['prijsproduct3']+$_SESSION['prijsproduct4']+$_SESSION['prijsproduct5']+$_SESSION['prijsproduct6'] ;
	define('EURO_SYMBOOL', chr(128));
	$_SESSION['euro'] = EURO_SYMBOOL;
	$_SESSION['verzendkosten'] = 5;
	$_SESSION['btw']=0.21* $_SESSION['somproducten'];
	if($_SESSION['somproducten']<200)
		{
		$_SESSION['korting']=0 ;
		}
		else
		{
		$_SESSION['korting']=0.1*$_SESSION['somproducten'];
		}
		$_SESSION['totaalbedrag']=$_SESSION['somproducten']+$_SESSION['verzendkosten']-$_SESSION['korting'];
		$iSomProductenRounded = round($_SESSION['somproducten'], 2);
		$iVerzendKostenRounded = round($_SESSION['verzendkosten'], 2);
		$iBTWRounded = round($_SESSION['btw'], 2);
		$iKortingRounded = round($_SESSION['korting'], 2);
		$iTotaalbedragRounded = round($_SESSION['totaalbedrag'], 2);
		$sSomProductenRounded = number_format($iSomProductenRounded, 2);
		$sVerzendKostenRounded = number_format($iVerzendKostenRounded, 2);
		$sBTWRounded = number_format($iBTWRounded, 2);
		$sKortingRounded = number_format($iKortingRounded, 2);
		$sTotaalbedragRounded = number_format($iTotaalbedragRounded, 2);
		$sSomProductenRounded = str_replace('.', ',', $sSomProductenRounded);
		$sVerzendKostenRounded = str_replace('.', ',', $sVerzendKostenRounded);
		$sBTWRounded = str_replace('.', ',', $sBTWRounded);
		$sKortingRounded = str_replace('.', ',', $sKortingRounded);
		$sTotaalbedragRounded = str_replace('.', ',', $sTotaalbedragRounded);
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="description" content="">
        <meta name="author" content="">
        <title>New Age - Start Bootstrap Theme</title>
        <!-- Bootstrap Core CSS -->
        <link href="lib/bootstrap/css/bootstrap.min.css" rel="stylesheet">
        <!-- Custom Fonts -->
        <link href="https://fonts.googleapis.com/css?family=Lato" rel="stylesheet">
        <link href="https://fonts.googleapis.com/css?family=Catamaran:100,200,300,400,500,600,700,800,900" rel="stylesheet">
        <link href="https://fonts.googleapis.com/css?family=Muli" rel="stylesheet">
        <!-- Plugin CSS -->
        <link rel="stylesheet" href="lib/font-awesome/css/font-awesome.min.css">
        <link rel="stylesheet" href="lib/simple-line-icons/css/simple-line-icons.css">
        <link rel="stylesheet" href="lib/device-mockups/device-mockups.min.css">
        <!-- Theme CSS -->
        <link href="css/new-age.min.css" rel="stylesheet">
        <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
        <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
        <!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
        <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
        <![endif]-->
    </head>
    <body id="page-top">
        <nav id="mainNav" class="navbar navbar-default navbar-fixed-top">
            <div class="container">
                <!-- Brand and toggle get grouped for better mobile display -->
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                        <span class="sr-only">Toggle navigation</span> Menu <i class="fa fa-bars"></i>
                    </button>
                    <a class="navbar-brand page-scroll" href="inde.php">SeFrMa Webshop</a>
                </div>
                <!-- Collect the nav links, forms, and other content for toggling -->
                <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                    <ul class="nav navbar-nav navbar-right">
                        <li>
                            <a class="" href="inde.php">Home</a>
                        </li>
                    </ul>
                </div>
                <!-- /.navbar-collapse -->
            </div>
            <!-- /.container-fluid -->
        </nav>
        <header>
            <div id="myCarousel" class="carousel slide" data-ride="carousel">
                <!-- Indicators -->
                <ol class="carousel-indicators">
                    <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
                    <li data-target="#myCarousel" data-slide-to="1"></li>
                </ol>
                <div class="carousel-inner" role="listbox">
                    <div class="item active">
                        <img class="first-slide" src="img/GamingSetup.jpg" alt="First slide">
                        <div class="container">
                            <div class="carousel-caption">
                                <div class="col-lg-12 text-center">
                                    <div class="section-heading">
                                        <h3>Uw bestelling:</h3>
                                        <hr>
                                    </div>
                                </div>
									<?php
										echo'
										<div class="container">
										  <table class="table">
											<tbody>
											  <tr>
												<td>Subtotaal</td>
												<td> &euro;'. $sSomProductenRounded . '</td>
											  </tr>
											  <tr>
												<td>Verzendkosten</td>
												<td> &euro;'. $sVerzendKostenRounded . '</td>
											  </tr>
											  <tr>
												<td>Btw</td>
												<td> &euro;'. $sBTWRounded . '</td>
											  </tr>
											  <tr>
												<td>Korting</td>
												<td> &euro;'. $sKortingRounded . '</td>
											  </tr>
											  <tr>
												<td>Totaalbedrag</td>
												<td> &euro;'. $sTotaalbedragRounded . '</td>
											  </tr>
											</tbody>
										  </table>
										</div>';
										$fp = fopen("rekening.doc","a+") or exit("unable to open the file");
										if($fp != null)
										{
										fwrite($fp,'Aantal:			'."\n");
										fwrite($fp,'Assassins Creed IV: Black Flag:		'.$_SESSION['aantalproduct1']. "\n");
										fwrite($fp,'Assassins Creed Syndicate:  			'.$_SESSION['aantalproduct2']. "\n");
										fwrite($fp,'CounterStrike: Global Offensive:		'.$_SESSION['aantalproduct3']. "\n");
										fwrite($fp,'CounterStrike: Source:				'.$_SESSION['aantalproduct4']. "\n");
										fwrite($fp,'Call of Duty: Ghosts:				'.$_SESSION['aantalproduct5']. "\n");
										fwrite($fp,'Call of Duty: Advanced Warfare:		'.$_SESSION['aantalproduct6']. "\n");
										fwrite($fp,'SubTotaal:						'.$_SESSION['euro'].$_SESSION['somproducten']. "\n");
										fwrite($fp,'Verzendkosten:  					'.$_SESSION['euro'].$_SESSION['verzendkosten']. "\n");
										fwrite($fp,'BTW:							'.$_SESSION['euro'].$_SESSION['btw']. "\n");
										fwrite($fp,'Korting:						'.$_SESSION['euro'].$_SESSION['korting']. "\n");
										fwrite($fp,'Totaalbedrag					'.$_SESSION['euro'].$_SESSION['totaalbedrag']. "\n"."\n");
										}
										fclose($fp);
								?>
                            </div>
                        </div>
                    </div>
                </div>
                <!-- /.carousel -->
            </div>
        </header>
     </body>
</html>
