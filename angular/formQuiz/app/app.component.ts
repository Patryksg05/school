import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'Kartkowka';
  name: string = "";
  email: string = "";
  status: string = "";
  rating: number = 1;

  onSubmit()
  {
    console.log("PUBLIC SURVEY\n" +
                "User name: " + this.name +
                "\nUser email: " + this.email +
                "\nUser status: " + this.status +
                "\nUser rating: " + this.rating);

    const popUpDiv: HTMLElement | null = document.getElementById("popup");
    const form: HTMLElement | null = document.getElementById("form");

    popUpDiv?.classList.add("open-popup");
    popUpDiv?.classList.remove("popup");

    let n = document.createElement("p");
    let e = document.createElement("p");
    let s = document.createElement("p");
    let r = document.createElement("p");

    let btn = document.createElement("button");

    n.innerHTML = "User name: " + this.name;
    e.innerHTML = "User email: " + this.email;
    s.innerHTML = "User status: " + this.status;
    r.innerHTML = "User rating: " + this.rating;
    btn.innerHTML = "OK";

    btn.style.backgroundColor = 'rgba(152, 152, 152, 0.6)';
    btn.style.width = '100%';
    btn.style.fontWeight = 'bold';
    btn.style.border = 'none';
    btn.style.outline = 'none';
    btn.style.borderRadius = '4px';
    btn.style.padding = '4px';
    btn.style.boxShadow = '0 2px 2px rgba(152,152,152, 0.6)';

    btn.addEventListener("click", () => {
      window.location.reload();
    })

    popUpDiv?.append(n);
    popUpDiv?.append(e);
    popUpDiv?.append(s);
    popUpDiv?.append(r);
    popUpDiv?.append(btn);

    form?.classList.add("visiiblity-hidden");
  }

  onReset()
  {

  }
}
