function initTask() {
    if(window.localStorage.getItem("name") == null) {
        const name = window.prompt("Your name: ");       
        window.localStorage.setItem("name", name);
    }
    
    document.querySelectorAll("span")[0].innerHTML = 
        window.localStorage.getItem("name");
    // console.log(window.localStorage.getItem("name"));

    let taskList = JSON.parse(localStorage.getItem("taskList"));
    if(taskList == null) {
        taskList = Array();
        window.localStorage.setItem("taskList", 
                        JSON.stringify(taskList));
    }

    keyTrigger();
    showTask();
}    

const btn = document.querySelector("button");
btn.addEventListener("click", () => {
        if(document.querySelector("#task").value != "") {
            let task = document.getElementById("task").value;
            let taskList = JSON.parse(window.localStorage.getItem("taskList"));
            taskList.push(task);
            window.localStorage.setItem("taskList", JSON.stringify(taskList));
            document.getElementById("task").value = "";
            showTask();
    }
});

function keyTrigger() {
    const input = document.querySelector("#task");
    input.addEventListener("keypress", function(event) {
        if(event.key === "Enter") {
            event.preventDefault();
            document.querySelector("button").click();
        }
    })
}

function showTask(){
    if(window.localStorage.getItem("name") != null) {
        const taskListDiv = document.querySelector("#taskList");
        let taskArray = JSON.parse(window.localStorage.getItem("taskList"));
        let list = "";
        list += "<ul>";
        for(let i=0; i<taskArray.length; i++) {
            list += "<li>" + taskArray[i] + 
                " <span onclick=\"removeTask("+i+")\" style='font-size: 20px; cursor: pointer; color:red' class='fa'>&#xf014</span></li>";
        }
        list += "</ul>";
        taskListDiv.innerHTML = list;
    }
    else
        initTask();
}

function removeTask(task) {
    let taskArray = JSON.parse(window.localStorage.getItem("taskList"));
    taskArray.splice(task, 1);
    window.localStorage.setItem("taskList", JSON.stringify(taskArray));
    showTask();
}
