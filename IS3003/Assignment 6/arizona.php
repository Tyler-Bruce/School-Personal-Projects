<html>
<head>
<title> Arizona </title>
</head>

<body style="padding:30px;">

<?php
include 'header.html';
?>


<h2> Arizona </h2>
<?php
$currentFileName = basename($_SERVER['PHP_SELF']);

$period = strpos ($currentFileName, ".");

$stateName = (substr($currentFileName, 0, $period));

$imageName ="stateinfo/$stateName.jpg";
$imageData ="stateinfo/$stateName-data.txt";

echo "<img src=\"$imageName\" alt=\"$stateName\" width=\"240\" height=\"150\">";
echo "<p>";
include "$imageData";

?>
<?php
include 'footer.html';
?>
</body>
</html>