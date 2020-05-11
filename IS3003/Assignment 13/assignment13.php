
<html>
<head>
<title> Random Pictures - Assignment 13 </title>
</head>

<body style="padding:30px;">

<h2> Refresh Page </h2>
Tyler Bruce <p>

<form method="post" name="xyz" id="xyz"
	action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">

<?php

$random = rand();
if ($random % 7 == 0)
{
	echo "<img src=\"images/R.jpg\" width=\"240\" height=\"150\">";
	echo "<p>";
	
}
if ($random % 7 == 1)
{
	echo "<img src=\"images/A.jpg\" width=\"240\" height=\"150\">";
	echo "<p>";
	
}
if ($random % 7 == 2)
{
	echo "<img src=\"images/N.jpg\" width=\"240\" height=\"150\">";
	echo "<p>";
	
}
if ($random % 7 == 3)
{
	echo "<img src=\"images/D.jpg\" width=\"240\" height=\"150\">";
	echo "<p>";
	
}
if ($random % 7 == 4)
{
	echo "<img src=\"images/O.jpg\" width=\"240\" height=\"150\">";
	echo "<p>";
	
}
if ($random % 7 == 5)
{
	echo "<img src=\"images/M.jpg\" width=\"240\" height=\"150\">";
	echo "<p>";
	
}
if ($random % 7 == 6)
{
	echo "<img src=\"images/R.jpg\" width=\"240\" height=\"150\">";
	echo "<img src=\"images/A.jpg\" width=\"240\" height=\"150\">";
	echo "<img src=\"images/N.jpg\" width=\"240\" height=\"150\">";
	echo "<img src=\"images/D.jpg\" width=\"240\" height=\"150\">";
	echo "<img src=\"images/O.jpg\" width=\"240\" height=\"150\">";
	echo "<img src=\"images/M.jpg\" width=\"240\" height=\"150\">";
	echo "<p>";
	
}


?>

</form>
</body>

</html>