<html>
<head>
<title> Alabama </title>
</head>

<body style="padding:30px;">

<?php
include 'header.html';
?>


<h2> Alabama </h2>
<?php
$currentFileName = basename($_SERVER['PHP_SELF']);
//echo "currentFileName = $currentFileName <br>";

$period = strpos ($currentFileName, ".");

//echo "period = $period <br>";

$stateName = (substr($currentFileName, 0, $period));
//echo "stateName = $stateName <br>";

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