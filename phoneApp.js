// JavaScript for Phone Application Demo Program
// Jim Skon, Kenyon College, 2017
var operation;  // operation

$(document).ready(function () {
    $("#search-btn").click(getMatches);

    operation = "Find Last";
    $("#clear").click(clearResults);

    $(".dropdown-menu li a").click(function(){
	console.log("pick!"+$(this).text());
	$(this).parents(".btn-group").find('.selection').text($(this).text());
	operation=$(this).text();
	changeOption(operation);
    });
});

changeOption("Find Last");

// Build output table from comma delimited list
function buildTable(list) {
    var a = list.split(",");
    if (a.length < 1) {
	return "<h3>Internal Error</h3>";
    } else if (a.length == 1) {
	return "<h3>Nothing Found</h3>";
    } else {
	var result = '<table class="w3-table-all w3-hoverable" border="2"><tr><th>First</th><th>Last</th><th>Phone</th><th>Type</th><th>Action</th><tr>';
	var aLen = a.length;
	for (var i = 1; i < aLen; i+=5) {
	    result += "<tr><td>"+a[i]+"</td><td>"+a[i+1]+"</td><td>"+a[i+2]+"</td><td>"+a[i+3]+"</td>";
	    result += "<td><button type='button' rec='"+a[i+4]+"' class='btn btn-primary btn-sm edit'>Edit</button> ";
	    result += "<button type='button' rec='"+a[i+4]+"' class='btn btn-primary btn-sm delete'>Delete</button></td></tr>";
	}
	result += "</table>";
	return result;
    }
}

function processEdit() {
    alert("Edit Record: " + $(this).attr('rec'));
}

function processDelete() {
    alert("Delete Record: " + $(this).attr('rec'));
}

function changeOption(operation) {
    if (operation=="Add Entry") {
	$('.inputdata').show();
	$('.searchbox').hide();
	$('.results').hide();
    } else if (operation=="Find Last") {
	$('.inputdata').hide();
	$('.results').show();
	$('.searchbox').show();
    }
}
function processResults(results) {
    console.log("Results:"+results);
    $('#searchresults').empty();
    $('#searchresults').append(buildTable(results));
    // set up action for buttons
    $(".edit").click(processEdit);
    $(".delete").click(processDelete);


}

function clearResults() {
    $('#searchresults').empty();
}

function getMatches(){
    console.log($('#search').val());

    $('#searchresults').empty();
    $.ajax({
		url: '/cgi-bin/skon_phoneApp.cgi?find='+$('#search').val()+'&operation='+operation,
		dataType: 'text',
		success: processResults,
		error: function(){alert("Error: Something went wrong");}
    });

}
