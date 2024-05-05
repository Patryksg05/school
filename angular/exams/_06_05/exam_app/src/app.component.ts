import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'first_exam_app';

  courses:string[] = ["Programowanie w C#", "Angular dla  początkujących", "Kurs  Django"]
  name:string = "";
  course:string = "";

  onSubmit():void
  {
      if(this.name != " " && this.course != " ")
        console.log(this.name + this.course)
  }
}
