<?php
session_start();
 if ($_SESSION['ingelogd'] != true){
 	 header ('Location: inlog.php');
 }
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
            <div class="navbar-header">
                <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span> Menu <i class="fa fa-bars"></i>
                </button>
                <a class="navbar-brand page-scroll" href="#page-top">SeFrMa Webshop</a>
            </div>
            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                <ul class="nav navbar-nav navbar-right">
                    <li>
                        <a class="page-scroll" href="#Assasinscreed">Aanbod</a>
                    </li>
                    <li>
                        <a class="page-scroll" href="#kopen">Bestellen</a>
                    </li>
                    <li>
                        <a class="page-scroll" href="#contact">Over de makers</a>
                    </li>
                    <li>
                        <a class="" href="uitloggen.php">Uitloggen</a>
                    </li>
                </ul>
            </div>
        </div>
    </nav>
    <header>
        <div id="myCarousel" class="carousel slide" data-ride="carousel">
            <!-- Indicators -->
            <ol class="carousel-indicators">
                <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
                <li data-target="#myCarousel" data-slide-to="1"></li>
                <li data-target="#myCarousel" data-slide-to="2"></li>
            </ol>
            <div class="carousel-inner" role="listbox">
                <div class="item active">
                    <img class="first-slide" src="img/GamingSetup.jpg" alt="First slide">
                    <div class="container">
                        <div class="carousel-caption">
                            <h1>De beste games!</h1>
                            <p><a class="btn btn-lg btn-primary page-scroll" href="#Assasinscreed" role="button">Zie ons aanbod</a></p>
                        </div>
                    </div>
                </div>
                <div class="item">
                    <img class="second-slide" src="img/GamingSetup2.jpg" alt="Second slide">
                    <div class="container">
                        <div class="carousel-caption">
                            <h1>De goedkoopste prijzen!</h1>
                            <p>Wij verzekeren de goedkoopste prijs over de hele interwebz!</p>
                            <p><a class="btn btn-lg btn-primary page-scroll" href="#Assasinscreed" role="button">Zie ons aanbod</a></p>
                        </div>
                    </div>
                </div>
                <div class="item">
                    <img class="third-slide" src="img/GamingSetup4.jpg" alt="Third slide">
                    <div class="container">
                        <div class="carousel-caption">
                            <h1>De snelste levering!</h1>
                            <p>Wij hebben de snelste levering van de hele interwebz!</p>
                            <p><a class="btn btn-lg btn-primary page-scroll" href="#Assasinscreed" role="button">Zie ons aanbod</a></p>
                        </div>
                    </div>
                </div>
            </div>
            <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
                <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
                <span class="sr-only">Previous</span>
            </a>
            <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
                <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
                <span class="sr-only">Next</span>
            </a>
        </div>
    </header>
    <section id="Assasinscreed" class="games textcolorwhite bg-assasinscreed text-center">
        <div class="container">
            <div class="col-md-8 col-md-offset-2">
                <h2 class="section-heading">Assasins Creed</h2>
            </div>
            <div class="row">
                <div class="col-md-5">
                    <a href="#kopen" class="page-scroll"><img src="img/AC4BlackFlagGameResized.png" alt="ACGame1"></a>
                    <h1> Assassin's Creed IV: Black Flag</h1>
                    <h2> &euro; 10</h2>
                    <p>Assassin's Creed IV: Black Flag is a 2013 action-adventure game, and the sixth main installment in the Assassin's Creed series. A sequel to 2012's Assassin's Creed III, the game has the player take on the role of an Abstergo Entertainment research analyst as they explore the story of Edward Kenway – father to Haytham Kenway, grandfather to Ratonhnhaké:ton, and an ancestor of Desmond Miles.Assassin's Creed IV: Black Flag is set primarily on and around the islands in the Caribbean Sea during the Golden Age of Piracy in the early 18th century, with the three major cities consisting of Havana, Nassau, and Kingston.</p>
                </div>
                <div class="col-md-5 col-md-offset-2">
                    <a href="#kopen" class="page-scroll"><img src="img/ResizedDeGoedeAC.jpg" alt="ACGame1"></a>
                    <h1>Assassin's Creed Syndicate</h1>
                    <h2> &euro; 20</h2>
                    <p>Assassin's Creed Syndicate is an action-adventure stealth video game developed by Ubisoft Quebec and published by Ubisoft. It was released on October 23, 2015, for the PlayStation 4 and Xbox One, and on November 19, 2015, for Microsoft Windows. It is the ninth major installment in the Assassin's Creed series, and the successor to 2014's Assassin's Creed Unity. The plot is set in a fictional history of real-world events and follows the centuries-old struggle between the Assassins, who fight for peace with liberty, and the Templars, who desire peace through order. The story is set in Victorian era London and follows twin assassins Jacob and Evie Frye as they navigate the corridors of organized crime, and take back the city from Templar control. The open world design lets players freely roam London. The game is played from a third-person view and its world is navigated on foot or by carriage. The game introduces new traveling systems and refined combat and stealth mechanics. Players control the two lead protagonists—twins Jacob and Evie Frye—throughout the game's story, switching between them both during and outside of missions. Unlike its direct predecessors, Syndicate does not feature any multiplayer gameplay.</p>
                </div>
                <div class="col-md-4 col-md-offset-4">
                    <p><a class="btn btn-lg btn-primary page-scroll" href="#kopen" role="button">Bestel!</a></p>
                </div>
            </div>
        </div>
    </section>
    <section id="Counterstrike" class="games textcolorred bg-counterstrike text-center">
        <div class="container">
            <div class="col-md-8 col-md-offset-2">
                <h2 class="section-heading">CounterStrike</h2>
            </div>
            <div class="row">
                <div class="col-md-5">
                    <a href="#kopen" class="page-scroll"><img src="img/counterstrikegoed.png" alt="ACGame1"></a>
                    <h1>CSGO</h1>
                    <h2> &euro; 30</h2>
                    <p>Counter-Strike: Global Offensive (CS: GO) will expand upon the team-based action gameplay that it pioneered when it was launched 14 years ago."Counter-Strike took the gaming industry by surprise when the unlikely MOD became the most played online PC action game in the world almost immediately after its release in August 1999," said Doug Lombardi at Valve. "For the past 12 years, it has continued to be one of the most-played games in the world, headline competitive gaming tournaments and selling over 25 million units worldwide across the franchise. CS: GO promises to expand on CS' award-winning gameplay and deliver it to gamers on the PC as well as the next gen consoles and the Mac."</p>
                </div>
                <div class="col-md-5 col-md-offset-2">
                    <a href="#kopen" class="page-scroll"><img src="img/counterstrike2goed.png" alt="ACGame1"></a>
                    <h1>CS 1.6</h1>
                    <h2> &euro; 40</h2>
                    <p>Play the world's number 1 online action game. Engage in an incredibly realistic brand of terrorist warfare in this wildly popular team-based game. Ally with teammates to complete strategic missions. Take out enemy sites. Rescue hostages. Your role affects your team's success. Your team's success affects your role.</p>
                </div>
                <div class="col-md-4 col-md-offset-4">
                    <p><a class="btn btn-lg btn-primary page-scroll" href="#kopen" role="button">Bestel!</a></p>
                </div>
            </div>
        </div>
    </section>
    <section id="CallOfDuty" class="games textcolorwhite bg-callofduty text-center">
        <div class="container">
            <div class="col-md-8 col-md-offset-2">
                <h2 class="section-heading">Call of Duty</h2>
            </div>
            <div class="row">
                <div class="col-md-5">
                    <a href="#kopen" class="page-scroll"><img src="img/CodGhosts.jpg" alt="ACGame1"></a>
                    <h1>Call of Duty: Ghosts</h1>
                    <h2> &euro; 50</h2>
                    <p>Call of Duty®: Ghosts is an extraordinary step forward for one of the largest entertainment franchises of all-time. This new chapter in the Call of Duty® franchise features a new dynamic where players are on the side of a crippled nation fighting not for freedom, or liberty, but simply to survive.Fueling this all new Call of Duty experience, the franchise's new next-gen engine delivers stunning levels of immersion and performance, all while maintaining the speed and fluidity of 60 frames-per-second across all platforms.</p>
                </div>
                <div class="col-md-5 col-md-offset-2">
                    <a href="#kopen" class="page-scroll"><img src="img/AWgoed.png" alt="ACGame1"></a>
                    <h1>Call of Duty: Advanced Warfare</h1>
                    <h2> &euro; 60</h2>
                    <p>Call of Duty®: Ghosts is an extraordinary step forward for one of the largest entertainment franchises of all-time. This new chapter in the Call of Duty® franchise features a new dynamic where players are on the side of a crippled nation fighting not for freedom, or liberty, but simply to survive.Fueling this all new Call of Duty experience, the franchise's new next-gen engine delivers stunning levels of immersion and performance, all while maintaining the speed and fluidity of 60 frames-per-second across all platforms.</p>
                </div>
                <div class="col-md-4 col-md-offset-4">
                    <p><a class="btn btn-lg btn-primary page-scroll" href="#kopen" role="button">Bestel!</a></p>
                </div>
            </div>
        </div>
    </section>
    <section id="kopen" class="kopen">
        <div class="container">
            <div class="row">
                <div class="col-lg-12 text-center">
                    <div class="section-heading">
                        <h2>Koop</h2>
                        <p class="text-muted">Koop snel! OP=OP</p>
                        <hr>
                    </div>
                </div>
                <div class="col-lg-12 text-center">
                    <p>Aantal:</p>
                </div>
            </div>
            <form class="form-horizontal" action="AantalVerwerking.php" method="get">
                <div class="form-group">
                    <label class="control-label col-sm-2">Assassin's Creed IV: Black Flag</label>
                    <div class="col-sm-10">
                        <input name="AC4Amount" type="number" class="form-control" placeholder="&euro; 10" min="0">
                    </div>
                </div>
                <div class="form-group">
                    <label class="control-label col-sm-2">Assassin's Creed Syndicate</label>
                    <div class="col-sm-10">
                        <input name="ACSAmount" type="number" class="form-control" placeholder="&euro; 20" min="0">
                    </div>
                </div>
                <div class="form-group">
                    <label class="control-label col-sm-2">CounterStrike: Global Offensive</label>
                    <div class="col-sm-10">
                        <input name="CSGOAcount" type="number" class="form-control" placeholder="&euro; 30" min="0">
                    </div>
                </div>
                <div class="form-group">
                    <label class="control-label col-sm-2">CounterStrike: Source</label>
                    <div class="col-sm-10">
                        <input name="CSSAmount" type="number" class="form-control" placeholder="&euro; 40" min="0">
                    </div>
                </div>
                <div class="form-group">
                    <label class="control-label col-sm-2">Call of Duty: Ghosts</label>
                    <div class="col-sm-10">
                        <input name="CODGAmount" type="number" class="form-control" placeholder="&euro; 50" min="0">
                    </div>
                </div>
                <div class="form-group">
                    <label class="control-label col-sm-2">Call of Duty: Advanced Warfare</label>
                    <div class="col-sm-10">
                        <input name="CODAWAmount" type="number" class="form-control" placeholder="&euro; 60" min="0">
                    </div>
                </div>
                <div class="form-group">
                    <div class="col-sm-offset-2 col-sm-10">
                        <button type="submit" class="btn btn-default">Submit</button>
                    </div>
                </div>
            </form>
        </div>
    </section>
    <section id="contact" class="contact bg-primary">
        <div class="container">
            <div class="col-md-8 col-md-offset-2">
                <h1>Informatie:</h1>
            </div>
            <div class="row">
                <div class="col-md-4">
                    <p>Sebastian</p>
                </div>
                <div class="col-md-4">
                    <p>Martijn</p>
                </div>
                <div class="col-md-4">
                    <p>Frank</p>
                </div>
            </div>
            <div class="col-md-4 col-md-offset-4">
                <p>Deze webpagina is gemaakt voor ons informatica eindopdracht van VWO 4. Hiervoor hebben wij Bootstrap gebruikt, omdat wij vinden dat dit een heel mooi resultaat geeft.</p>
            </div>
        </div>
    </section>
    <footer>
        <div class="container">
            <p>&copy; 2018 (lol) SeFrMa. All rights reserved</p>
        </div>
    </footer>
    <!-- jQuery -->
    <script src="lib/jquery/jquery.min.js"></script>
    <!-- Bootstrap Core JavaScript -->
    <script src="lib/bootstrap/js/bootstrap.min.js"></script>
    <!-- Plugin JavaScript -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.3/jquery.easing.min.js"></script>
    <!-- Theme JavaScript -->
    <script src="js/new-age.min.js"></script>
</body>
</html>
