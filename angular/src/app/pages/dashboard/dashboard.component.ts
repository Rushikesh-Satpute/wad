import { HttpClient } from '@angular/common/http';
import { Component } from '@angular/core';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.css']
})
export class DashboardComponent {

  users: any[]=[];
  constructor(private http: HttpClient){
    this.loadUsers();
  }

  loadUsers() {
    debugger;
    alert("user loading...")
  }
}
