import { Component, createEnvironmentInjector } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'Revision before quiz';
  name: string = "";
  email: string = "";
  age: number = 10;
  language: string = "";
  type: string = "Full-Stack";

  onSubmit()
  {
    console.log("Name: " + this.name +
                "\nEmail: " + this.email +
                "\nAge: " + this.age +
                "\nLanguage: " +  this.language +
                "\nProgramming Approache: " + this.type);

    const popUpDiv: HTMLElement | null = document.getElementById("popup");
    const form: HTMLElement | null = document.getElementById("form");

    // console.log(popUpDiv);
    popUpDiv?.classList.add("open-popup");
    popUpDiv?.classList.remove("popup");

    const n = document.createElement("p");
    const e = document.createElement("p");
    const a = document.createElement("p");
    const fl = document.createElement("p");
    const t = document.createElement("p");
    n.innerHTML = "Your name: " + this.name;
    e.innerHTML = "Your email: " + this.email;
    a.innerHTML = "Your age: " + this.age.toString();
    fl.innerHTML = "Your favourite language: " + this.language;
    t.innerHTML = "Your approache programming: " +  this.type;
    popUpDiv?.append(n);
    popUpDiv?.append(e);
    popUpDiv?.append(a);
    popUpDiv?.append(fl);
    popUpDiv?.append(t);

    const button = document.createElement("button");
    button.style.backgroundColor = 'rgba(152, 152, 152, 0.6)';
    button.style.width = '100%';
    button.style.border = '0';
    button.style.outline = 'none';
    button.style.borderRadius = '4px';
    button.style.padding = '10px 0';
    button.style.fontWeight = 'bold';
    button.style.fontSize = '18px';
    let text = document.createTextNode("OK");
    button.appendChild(text);
    popUpDiv?.appendChild(button);

    form?.classList.add("visibility-hidden");

    button.addEventListener("click", function(){
      window.location.reload();
    })
  }

  onReset()
  {
    console.log('hard reset :))');
  }
}
