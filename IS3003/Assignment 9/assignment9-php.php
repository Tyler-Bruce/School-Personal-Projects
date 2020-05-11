<?php
$maxValue = 5;

function test_input($data)
{
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	return $data;
}

if ($_SERVER["REQUEST_METHOD"] == "POST")
{
	if (!empty($_POST["maxValue"]))
	{
		$maxValue = test_input($_POST["maxValue"]);
	}
}

$tempStr = "";
$tempStr = $tempStr . "Increasing Order: \n";
for ($index = 1; $index <= $maxValue; $index++)
{
	$tempStr = $tempStr . $index . " ";
}
$tempStr = $tempStr . "\n\n";
$tempStr = $tempStr . "Decreasing Order: \n";
for ($index = $maxValue; $index >= 1; $index--)
{
	$tempStr = $tempStr . $index . " ";
}
$tempStr = $tempStr . "\n\n";
$tempStr = $tempStr . "Even Numbers: \n";
for ($index = 1; $index <= $maxValue; $index++)
{
	if ($index % 2 == 0)
	{
	$tempStr = $tempStr . $index . " ";
	}
	else
	{
		continue;
	}
}
$tempStr = $tempStr . "\n\n";
$tempStr = $tempStr . "Squares: \n";
for ($index1 = 1; $index1 <= $maxValue; $index1++)
{
	for ($index2 = 1; $index2 <= $maxValue; $index2++)
	{
	$tempStr = $tempStr . "*";
	}
	$tempStr = $tempStr . "\n";
}
$tempStr = $tempStr . "\n\n";
$tempStr = $tempStr . "Multiplication Tables: \n";
for ($index = 1; $index <= $maxValue; $index++)
{
	$tempStr = $tempStr . $index . " * " . $index . " = " . $index * $index . "\n";
}
$tempStr = $tempStr . "\n\n";




?>


<html>
<head>
<title> PHP: For Loop </title>
</head>

<body style="padding:30px;">

<h2> PHP: For Loop </h2>
Tyler Bruce <p>

<form method="post" name="xyz" id="xyz"
	action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
	
<input type="text" name="maxValue" value="<?php echo $maxValue; ?>" />
<input type="submit" value="Display Results" /> <p>
<br />
<textarea name="results" rows="25" cols="50"><?php echo $tempStr; ?></textarea>
</form>
</body>

</html>