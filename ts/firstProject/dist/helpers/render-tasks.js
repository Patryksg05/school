export const render = (tasks, taskContainerElement) => {
    taskContainerElement.innerHTML = "";
    tasks.forEach((task, index) => {
        const taskElement = document.createElement("li");
        // taskElement.innerHTML = task.name;
        // taskContainerElement.appendChild(taskElement);
        if (task.category)
            taskElement.classList.add(task.category);
        const labelElement = document.createElement("label");
        const id = `task-${index}`;
        labelElement.innerHTML = task.title;
        labelElement.setAttribute("for", id);
        const checkBoxElement = document.createElement("input");
        checkBoxElement.type = "checkbox";
        checkBoxElement.name = task.title;
        checkBoxElement.id = id;
        checkBoxElement.checked = task.done;
        taskElement.appendChild(labelElement);
        taskElement.append(checkBoxElement);
        checkBoxElement.addEventListener("change", () => {
            task.done = !task.done;
        });
        taskContainerElement.appendChild(taskElement);
    });
};
