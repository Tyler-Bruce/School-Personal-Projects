<?php
$number1 = 0;
$number2 = 0;
$number3 = 0;
$result = "";
$status = "";
$grade = "";

function test_input($data) 
{
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	return $data;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
	if (!empty($_POST["number1"])) 
	{
		$number1 = test_input($_POST["number1"]);
	}
	
	if (!empty($_POST["number2"])) 
	{
		$number2 = test_input($_POST["number2"]);
	}
	if (!empty($_POST["number3"]))
	{
		$number3 = test_input($_POST["number3"]);
	}
	if (isset($_POST["grade"]))
	{
		$result = round(($number1 + $number2 + $number3) / 3);
		if ($result < 60)
		{
			$status = "Failing";
			$grade = "F";
		}
		else if ($result < 70)
		{
			$status = "Passing";
			$grade = "D";
		}
		else if ($result < 80)
		{
			$status = "Passing";
			$grade = "C";
		}
		else if ($result < 90)
		{
			$status = "Passing";
			$grade = "B";
		}
		else if ($result < 101)
		{
			$status = "Passing";
			$grade = "A";
		}
	}
	}
	

?>

<h2> PHP Health Calculator</h2>
James "Tyler" Bruce <p>


<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>  ">
<div>
<dl>
<dt>Membership
<dt><input type="radio" name="basic">Basic
<dt><input type="radio" name="plat">Platinum
<dt><input type="radio" name="gold">Gold
</dl>
</div>
<input type="submit" value="Calculate average" name="grade"> <p>
Average: <input type="text" name="Average" value="<?php echo $result;?>"><p> 
Status: <input type="text" name="Status" value="<?php echo $status;?>"><p>
Grade: <input type="text" name="Grade" value="<?php echo $grade;?>"><p>

</form>