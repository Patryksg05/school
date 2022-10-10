// typy reprezentujace obiekty => INTERFACE
export interface Task{
    title: string;
    done: boolean;
    // UNION TYPE => zbior kilku typow |
    category?: Category; // ? optional property
    // moga miec category ale nie musza
}

// type aliasing
export type Category = "general" | "work" 
| "sport" | "hobby";