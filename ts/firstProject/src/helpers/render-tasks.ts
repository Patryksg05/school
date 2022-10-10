import { Task } from "../types/types";

export const render = (tasks: Task[], taskContainerElement: HTMLElement) => {
    taskContainerElement.innerHTML = "";
    tasks.forEach((task, index)=> {
        const taskElement: HTMLElement = document.createElement("li");
        // taskElement.innerHTML = task.name;
        // taskContainerElement.appendChild(taskElement);

        if(task.category)
            taskElement.classList.add(task.category);

        const labelElement: HTMLLabelElement = document.createElement("label");
        const id: string = `task-${index}`;
        labelElement.innerHTML = task.title;
        labelElement.setAttribute("for", id);

        const checkBoxElement: HTMLInputElement = document.createElement("input");
        checkBoxElement.type = "checkbox";
        checkBoxElement.name = task.title;
        checkBoxElement.id = id;
        checkBoxElement.checked = task.done;

        taskElement.appendChild(labelElement);
        taskElement.append(checkBoxElement);
        checkBoxElement.addEventListener("change", () => {
            task.done = !task.done;
        })

        taskContainerElement.appendChild(taskElement);
    })
}