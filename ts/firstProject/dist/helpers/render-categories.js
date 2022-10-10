export const renderCategories = (categories, categoriesContainerElement) => {
    categories.forEach(category => {
        const categoryElement = document.createElement("li");
        const radioInputElement = document.createElement("input");
        radioInputElement.type = "radio";
        radioInputElement.name = "category";
        radioInputElement.value = category;
        radioInputElement.id = `category - ${category}`;
        categoryElement.appendChild(radioInputElement);
        const labelElement = document.createElement("label");
        labelElement.setAttribute("for", `category-${category}`);
        labelElement.innerHTML = category;
        categoryElement.append(labelElement);
        categoriesContainerElement.appendChild(categoryElement);
    });
};
