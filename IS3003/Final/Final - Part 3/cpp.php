<html>
<head>
<title> C++ </title>
</head>

<body style="padding:30px;">

<?php
include 'header.html';
?>


<h2> C++ </h2>
<?php
$currentFileName = basename($_SERVER['PHP_SELF']);
//echo "currentFileName = $currentFileName <br>";

$period = strpos ($currentFileName, ".");

//echo "period = $period <br>";

$language = (substr($currentFileName, 0, $period));
//echo "stateName = $stateName <br>";

$imageName ="languages/$language.jpg";
$imageData ="languages/$language-data.txt";

echo "<img src=\"$imageName\" alt=\"$language\" width=\"240\" height=\"150\">";
echo "<p>";
include "$imageData";

?>
<?php
include 'footer.html';
?>
</body>
</html>