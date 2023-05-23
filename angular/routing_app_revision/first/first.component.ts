import { Component } from '@angular/core';

@Component({
  selector: 'app-first',
  templateUrl: './first.component.html',
  styleUrls: ['./first.component.css']
})

export class FirstComponent {
  firstName: string = "Patryk";
  middleName: string = "Kamil";
  lastName: string = "Maciak";

  fruits: string[] = ['apple', 'banana', 'rasberry', 'strawberry', 'cranberries', 'blueberry']
}
