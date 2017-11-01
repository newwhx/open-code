import java.awt.event.*;
import java.lang.annotation.*;

@Target(ElementType.FIELD)
@Retention(RetentionPolicy.RUNTIME)
public @interface ActionListenerAnnotation{
		Class<? extends ActionListener> listener();
}
