<html>
<head>
<title> Java </title>
</head>

<body style="padding:30px;">

<?php
include 'header.html';
?>


<h2> Java </h2>
<?php
$currentFileName = basename($_SERVER['PHP_SELF']);

$period = strpos ($currentFileName, ".");

$language = (substr($currentFileName, 0, $period));

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