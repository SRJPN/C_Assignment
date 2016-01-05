var fs = require('fs');
var chance = require('chance')();
var argvs = process.argv;

var childProcess = require('child_process');


var splitByVoid = function(code){
	return code.split('void test_');
}

var refineName = function(name){
	var index = name.lastIndexOf('(');
	return name.slice(0,index).replace(/_/g,' ')
}

var refineCode = function(code,includes){
	return includes+"\n"+code;
}


var Test = function(includes, code, dependencies){
	var name = code.substr(0, code.indexOf("\n"));
	this.name = refineName(name);
	var program = code.replace(name, "int main(){\n");
	this.code = refineCode(program, includes);
	this.fileName = chance.word();
	this.failed = false;
	this.dependencies = dependencies;
}


var run_test = function(test){
	create_test_file(test);
	execute_test(test);
	delete_file(test);
}

var create_test_file = function(test){
	fs.writeFileSync("./"+test.fileName+".c",test.code);
};

var delete_file = function(test){
	fs.unlinkSync("./"+test.fileName+".c");
	fs.existsSync("./a.out") && fs.unlinkSync("./a.out");
};

var compile_test = function(test){
	var testFile = test.fileName;
	var testCMD = [testFile+".c"].concat(test.dependencies);
	test.compile = childProcess.spawnSync("gcc",testCMD)
};

var run = function(test){
	test.result = childProcess.spawnSync("./a.out");
}

var execute_test = function(test){
	compile_test(test);
	run(test);
	var result = test.result;
	if(result.error || !!result.stderr.toString()){
		test.failed = true;
		test.errorMsg = result.stderr;
	};
};

var create_report = function(tests){
	var failedCount = 0;
	tests.forEach(function(test){
		if(test.failed){
			present_Failed_test(test);
			failedCount++;
		}
		else
			present_passed_test(test);
	});
	console.log("\n",tests.length-failedCount+"/"+tests.length," Passed")
}

var present_Failed_test = function(test){
	console.log('✗ ',test.name);
	console.log("\t"+test.result.stderr.toString())
};

var present_passed_test = function(test){
	console.log('✔ ',test.name)
};

var main = function(){
	var fileName = argvs[2];
	var dependencies = argvs.slice(3);
	var file = fs.readFileSync("./"+fileName,"utf8");

	var includes = splitByVoid(file);
	var funcs = includes.splice(1);
	var tests = funcs.map(function(test){
		return new Test(includes, test, dependencies);
	});
	console.log("testing..............")
	tests.forEach(run_test);
	create_report(tests);
	fs.existsSync("./a.out") && fs.unlinkSync("./a.out");
};

main();
